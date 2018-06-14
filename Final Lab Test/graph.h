#include"minheap.h"
typedef struct list{
	int val;                       //vertex number
	int weight;	
	struct list * next;
}list;

typedef struct graph{
	list **l;
	int n;
}graph;
void initGraph(graph *g, int n);
int getn(graph *g);
void printGraph(graph *g);
graph *createGraphFromFile(char *filename);
edge *prims(graph *g, int start);

