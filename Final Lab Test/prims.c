#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include"graph.h"
char citynames[20][30];
edge e[100];
int n = 0;
int search(char *s) {
	int i;
	for(i = 0;i < n;i++)
		if(strcmp(citynames[i], s) == 0)
			return i;
	return -1;
}
/*returns NULL in case of non-existence of the file passed as input*/
graph* createGraph(char *file) {
	FILE *fp = fopen(file, "r");
	FILE *fpw = fopen("tmp", "w");
	if(fp == NULL){
		perror("");
		return NULL;
	}
	graph *g;
	char *s1 = (char*)malloc(30), *s2 = (char*)malloc(30);
	int u, v, w, i, j;
	int k = 0, **a;	
	
	while(fscanf(fp, "%s", s1) != -1){
		fscanf(fp, "%s", s2);
		u = search(s1);
		v = search(s2);
		if(u != -1 && v != -1) {                        //if both the citynames already present in the array
			e[k].u = u;
			e[k].v = v;
			fscanf(fp, "%d", &w);
			e[k].w = w;
		}
		else if(u != -1){
			strcpy(citynames[n], s2);
			e[k].u = u;
			e[k].v = n;
			fscanf(fp, "%d", &w);
			e[k].w = w;
			n++;
		}
		else if(v != -1){
			strcpy(citynames[n], s1);
			e[k].u = n;
			e[k].v = v;
			fscanf(fp, "%d", &w);
			e[k].w = w;
			n++;
		}
		else{
			strcpy(citynames[n], s1);
			n++;
			strcpy(citynames[n], s2);
			n++;
			e[k].u = n - 2;
			e[k].v = n - 1;
			fscanf(fp, "%d", &w);
			e[k].w = w;
		}
		k++;
	}
	fclose(fp);
	a = (int **)malloc(sizeof(int*) * n - 1);
	for(i = 0;i < n ;i++){
		a[i] = (int*)malloc(sizeof(int) * n);
		for(j = 0;j < n ;j++)
			a[i][j] = 0;
		for(j = 0;j <= k;j++)
			if(e[j].u == i){
				a[i][e[j].v] = e[j].w;
			}
	}
	fprintf(fpw, "%d\n", n);                //number of vertices in the graph
	for(i = 0;i < n;i++){
	for(j = 0;j < n;j++)
	fprintf(fpw, "%d ", a[i][j]);
	fprintf(fpw, "\n");
	}
	fclose(fpw);
	g = createGraphFromFile("tmp");         //fpw ---- file pointer of tmp, temporary file
	return g;
}

int main(int argc, char *argv[]) {
	int v1, v2, i, n;
	graph *g;
	edge *T;
	if(argc != 4){
	printf("wrong number of arguments");
	return errno;
	}
	g = createGraph(argv[1]);
	if(g == NULL)
	        return 0;
	n = getn(g);
	v1 = search(argv[2]);
	v2 = search(argv[3]);
	if(v1 == -1 || v2 == -1){
		printf("wrong input(argument) city");
		return errno;
	}
	
	/*path from city 1 to city 2*/
	T = prims(g, v1);
	int flag = 1;
	for(i = 0;i < n - 1;i++)
	        if(T[i].u == v2 || T[i].v == v2)
	                flag = 1;
	        else
	                flag = 0;
	        if(!flag){
	                printf("not possible");
	                return 0;
	        }
	printf("PATH FROM CITY 1 TO CITY 2 i.e. %s to %s----\n", argv[2], argv[3]);
	for(i = 0;i < n - 1;i++)
	        if(T[i].u == v2 || T[i].v == v2){
	        printf("%s-%s\n", citynames[T[i].u],  citynames[T[i].v]);
	        break;
	        }
	        else
	        printf("%s-", citynames[T[i].u]);

	/*path from city 2 to city 1*/
	T = prims(g, v2);
	for(i = 0;i < n - 1;i++)
	        if(T[i].u == v1 || T[i].v == v1)
	         flag = 1;
	        else
	         flag = 0;
	        if(!flag){
	                printf("not possible");
	                return 0;
	        }
	printf("PATH FROM CITY 2 TO CITY 1 i.e. %s to %s-----\n", argv[3], argv[2]);
	for(i = 0;i < n - 1;i++)
	        if(T[i].u == v1 || T[i].v == v1){
	        printf("%s-%s\n", citynames[T[i].u],  citynames[T[i].v]);
	        break;
	        }
	        else
	        printf("%s-", citynames[T[i].u]);
	
	return 0;
}
