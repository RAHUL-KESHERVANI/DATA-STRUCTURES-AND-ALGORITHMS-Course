#include <string.h>
#include "queue.h"

void qinit(queue *q){
	q->r = -1;
	q->f = 0;
	q->count = 0;
}
void enq(queue *q, char *str){
	q->r = (q->r + 1) % N;
	strcpy(q->data[q->r], str);	
	(q->count)++;
} 
char *deq(queue *q){
	char *t = q->data[q->f];
	q->f = (q->f + 1) % N;
	(q->count)--;
	return t;	
}
int qempty(queue *q){
	return q->count == 0;
}
int qfull(queue *q){
	return q->count == N;
}
