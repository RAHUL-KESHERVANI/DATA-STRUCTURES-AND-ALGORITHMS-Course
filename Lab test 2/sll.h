#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct data {
	int n;
	char name[30];
	double marks;
	int grace;
}data;
typedef struct node {
	data d;
	struct node *next;
}node;
typedef struct list {
	node *head, *tail;
}list;
void init(list *l);
long int length(list l);
void append(list *l, data d);
void removel(list *l, char *s);
void rotate(list *l, long int n);
void sort(list *l);
void printl(list l);











