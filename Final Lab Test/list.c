#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"list.h"
void init(list *l) {
	l->head = NULL;
	l->tail = NULL;
}
int length(list l) {
        int len = 0;
        node *p = l.head;
        while(p->next != l.head){
                p = p->next;
                len++;
        }
        return len;
}
void append(list *l, int val) {
	node *temp;	 
	temp =(node *)malloc(sizeof(node));
	temp->val = val;
	if(l->head == NULL){
		l->head = l->tail = temp;
		temp->next = l->head;
		return;
	}
	temp->next = l->head;
	l->tail->next = temp;
	l->tail = temp;
}
void traverse(list *l) {
	node *tmp;
	tmp = l->head;
	printf("[");
	if(!tmp){
		printf("]\n");
		return;
	}
	do{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}while(tmp != l->head);
	printf("]\n");
}
/*postion "pos" starts from 0*/
int remov(list *l, int pos) {
	int i, r;
	node *tmp, *p, *q;
	if(pos < 0)
		return INT_MIN;
	if(pos == 0){
		r = l->head->val;
		tmp = l->head->next;
		free(l->head);
		l->head = tmp;
		l->tail->next = l->head;
		return r;
	}
	p = l->head;
	q = NULL;
	for(i = 0;q != l->tail && i < pos;i++){
		q = p;
		p = p->next;
	}
	if(q == l->tail)		//pos is out of bounds of list
		return INT_MIN;
	if(p == l->tail){
		r = p->val;
		free(l->tail);
		p->next = l->head;
		l->tail = q;
		l->tail->next = l->head;
		return r;
	}
	tmp = p->next;
	r = p->val;
	free(p);
	q->next = tmp;
	return r;
}
void sort(list *l){
	int min = INT_MAX;
	node *minnode, *p, *q;
	p = q = l->head;
	int c = 0;		//just a flag for the first loop run;
	while(q != l->tail){
		min = INT_MAX;
		do{
			if(p->val < min){
				min = p->val;
				minnode = p;
			}
			p = p->next;
		}while(p != l->head);
		
		if(c){
		minnode->val = q->next->val;
		q->next->val = min;
		q = q->next;
		}
		else{
		c  = 1;
		minnode->val = q->val;
		q->val = min;
		}
		p = q->next;
	}
}

