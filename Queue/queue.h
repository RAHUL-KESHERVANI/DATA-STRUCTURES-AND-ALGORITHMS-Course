#include <stdlib.h>
typedef struct data {
    char name[16];
    unsigned int age;
}data;
typedef struct node {
	data d;
	struct node *p;
}node;
typedef struct queue {
 node *head;
 node *tail;
}queue;

void qinit(queue *n);
void enq(queue *n, data d);
data deq(queue *n);
int qfull(queue *n);
int qempty(queue *n);
