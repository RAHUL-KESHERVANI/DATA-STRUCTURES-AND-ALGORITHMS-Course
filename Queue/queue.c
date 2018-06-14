#include "queue.h"
void qinit(queue *n) {
	n->head = NULL;
	n->tail = NULL;
}
void enq(queue *n, data d) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->d = d;
	if(n->head == NULL)
		n->head = temp;
	temp->p = n->head;
	if(n->tail != NULL)
		n->tail->p = temp;
	n->tail = temp;
}
data deq(queue *n) {
	node *temp;
	data d;
	temp = n->head;
	d = n->head->d;
	if(n->head != n->tail) {
		n->head = n->head->p;
		n->tail->p = n->head;
	}
	else {
		n->head = NULL;
		n->tail = NULL;
	}
	temp->p = NULL;
	free(temp);
	return d;
}
int qfull(queue *n) {
	return 0;
}
int qempty(queue *n) {
	return n->head == NULL;
}
