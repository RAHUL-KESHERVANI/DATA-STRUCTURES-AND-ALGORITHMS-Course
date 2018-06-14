#include "sll.h"
/*initializes the list l*/
void init(list *l) {
	l->head = l->tail = NULL;
}
/*appends a node with data d at the end of the list l*/
void append(list *l, data d) {
	node *p, *new;
	new = (node *)malloc(sizeof(node));
	new->d = d;
	if(l->tail == NULL){			//for the first node
		l->head = l->tail = new;
		new->next = l->tail;
		return;
	}
	p = l->tail;
	p->next = l->tail = new;
	new->next = l->head;
}
/*returns the list l length*/
long int length(list l) {
	long int len = 1;
	node *p;
	if(l.head == NULL)
		return 0; 
	p = l.head;
	while(p != l.tail) {
		len++;
		p = p->next;
	}
	return len;
}

void removel(list *l, char *s) {
	node *p, *q;
	p = l->tail;
	q = l->head;
	int flag = 1;
	do {
		if(strcmp((q->d).name, s) == 0) {		//compares the passed string with node string
			
			if(l->tail == q){			//for q reaching the tail means the search is over
				l->tail = p;
				flag = 0;
			}
			p->next = q->next;
			free(q);
			q = p->next;
			if(p == l->tail) 			//when q is at the first node p is at the last(tail)
				l->head = q;			//if data is to be removed from the first node, head must be moved to 2nd node 
		}
		else{
			if(q == l->tail)			//for q reaching the tail means the search is over
				flag = 0;
			p = p->next;
			q = q->next;
		}
	}while(flag);
}

void rotate(list *l, long int n) {
	long int len = length(*l), i;
	node *p;
	/*moves the first node to last repeatedly*/
	for(i = 0;i < abs(len - n);i++) {		//len - n gives the number of elements to be sent at the tail*/
		p = l->head;				
		l->head = p->next;
		l->tail = p;
	}
}
/*rearranges the passed list into an ascending ordered list on the basis of marks*/
void sort(list *l) {
	node *p, *q, *t;
	data d;
	p = l->head;
	while(p != l->tail) {
		t = p;
		q = p->next;
		while(q != l->head) {
			if((t->d).marks > (q->d).marks){
				d = q->d;
				q->d = t->d;
				t->d = d;
			}
			q = q->next;
		}
		p = p->next;
	}
}
/*prints the list*/
void printl(list l) {
	node *p;
	p = l.head;
	do {
		printf("%d\t%s\t%.2lf\t%d\n", (p->d).n, (p->d).name, (p->d).marks, (p->d).grace);
		p = p->next;
	}while(p != l.head);
}

