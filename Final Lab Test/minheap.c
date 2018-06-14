#include<stdlib.h>
#include<stdio.h>
#include"minheap.h"
void heapInit(heap *h) {
        h->n = 0;
}

void swap(edge *a, int x, int y) {
	edge temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

void printHeap(heap *h){
        int i;
	for(i = 0;i <= h->n;i++)
	        printf("%d %d %d\n", h->a[i].u, h->a[i].v, h->a[i].w);
}

void heapInsert(heap *h, edge val) {
	int c, p;
	h->a[h->n] = val;
	c = h->n;
	p = (c - 1) / 2;
	while(c > 0) {
		if(h->a[c].w < h->a[p].w) {
			swap(h->a, c, p);
			c = p;
			p = (c - 1) / 2;
		}
		else
			break;
	}
	(h->n)++;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int findsmallest(edge *p, int a , int b, int c) {
	int x = MIN(p[a].w, p[b].w);
	int y = MIN(x, p[c].w);
	if(y == p[a].w)
		return a;
	if(y == p[b].w)
		return b;
	if(y == p[c].w)
		return c;
	return -1;
}

edge * heapRemove(heap *h) {
	edge *x = (edge*)malloc(sizeof(edge));
	x->u = h->a[0].u;
	x->v = h->a[0].v;
	x->w = h->a[0].w;
	int p, c1, c2, smallest;
	h->a[0] = h->a[h->n - 1];
	(h->n)--;
	p = 0;
	c1 = 2 * p + 1;
	c2 = 2 * p + 2;
	while(c1 < h->n) {
		smallest = findsmallest(h->a, p, c1, c2);
		if(smallest == p)
		break;
		swap(h->a, p, smallest);
		p = smallest;
		c1 = 2 * p + 1;
		c2  = 2 *p + 2;
	}
	return x;
}
int isempty(heap *h){
	return h->n == 0;
}
int isfull(heap *h) {
	return h->n == MAX;
}
