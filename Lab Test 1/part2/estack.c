#include"stack.h"
#include<stdlib.h>
static int n = 1;
int isempty(stack *s){
	return s->i == 0;
}
int isfull(stack *s){
	
	int *p;
	if(s->i == (MAX * n)){
		n++;
		p = realloc(s->a, MAX*n* sizeof(int));
		if(p == NULL){
			return 1;
		}
	s->a = p;
	}
	return 0;
}
void init(stack *s){
	s->i = 0;
	s->a = (int *)malloc(MAX * sizeof(int));
}
void push(stack *s, int x){
	s->a[s->i] = x;
	s->i++;
}
int pop(stack *s){
	int temp;
	temp = s->a[s->i - 1];
	s->i--;
	return temp;
}
