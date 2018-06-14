#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"

void initGraph(graph *g, int n) {
	int i;
	g->l = malloc(sizeof(list) * n);
	for(i = 0; i < n;i++){
		g->l[i] = (list *)malloc(sizeof(list));
		g->l[i]->val= i;	
		(g->l[i])->next = NULL;
	}
	g->n = n;
}
int getn(graph *g){
	return g->n;
}
void printGraph(graph *g) {
	int i, j;
	list *tmp;
	for(i = 0;i < g->n;i++){
		tmp = (g->l[i])->next;
		printf("%d:", i);
		while((tmp)){
			printf("%d(%d) ", tmp->val, tmp->weight);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

graph *createGraphFromFile(char *filename){
	FILE *fp;
	int n, i, j, t;
	list *tmp, *p;
	graph *g = (graph*)malloc(sizeof(graph));
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &n);
	
	initGraph(g, n);	
	g->n = n;
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			fscanf(fp, "%d", &t);
			if(t){
				tmp = (list *)malloc(sizeof(list));
				tmp->val = j;
				tmp->weight = t;
				tmp->next = NULL;
				p = g->l[i]->next;
				if(p){
				while(p->next)
					p = p->next;
				p->next = tmp;
				}
				
				else{
					g->l[i]->next = tmp;
				}	
			}
		}
	}
	fclose(fp);
	return g;
}
/*to check if the edge array e already has the vertix i or not*/
int check(edge *e,int t, int i) {
        int j; 
        for(j = 0;j <= t;j++)
                if(e[j].u == i)
                         return 0;
        return 1;
}
/*user should free the malloced memory returned after use...
...program uses minheap and prims algorithm to give the minimum spanning tree as return value
to check if minimum spanning tree returned is connected user should check if size of returned edges array T is equal to n-1 vertices i.e.                          getn(g) - 1 == sizeof(T)*/
edge *prims(graph *g, int start){
	int t = 0, j, i, minweight, k;
	int *visited = (int*)malloc(sizeof(int)*g->n);
	edge e;
	list *p;
	heap *h = (heap *)malloc(sizeof(heap));
	heapInit(h);
	edge *T = (edge*)malloc(sizeof(edge)*(g->n - 1));
	edge d;
	d.u = -1;
	d.v = -1;
	d.w = -1;
	for(i = 0;i < g->n - 1;i++)
	T[i] = d;
	for(i = 0;i < g->n;i++)
		visited[i] = 0;
	visited[start] = 1;
	for(k = 0;k < g->n - 1;k++){
		while(!isempty(h))
			heapRemove(h);
		for(i = 0;i < g->n;i++){
			if(visited[i] && check(T, t, i)){               //func check is to check for circular paths 
				p = g->l[i]->next;
				while(p){
					if(!visited[p->val]){
						e.u = i;
						e.v = p->val;
						e.w = p->weight;
						heapInsert(h, e);
					}
					p = p->next;	
				}
			}
		}
		if(!isempty(h)){
		        T[t] = *(heapRemove(h));
		        visited[T[t].v] = 1;
		        t++;
		}
	}
	free(visited);
	return T;
}

