#define MAX 32
typedef struct edge{
	int v;
	int u;
	int w;	//weight
}edge;
typedef struct heap {
	edge a[MAX];
	int n;
}heap;

int isempty(heap *h);
int isfull(heap *h);
void heapInit(heap *h);
edge* heapRemove(heap *h);
void heapInsert(heap *h, edge val);

