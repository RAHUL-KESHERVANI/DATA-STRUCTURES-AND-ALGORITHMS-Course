#include<stdio.h>
#include"oddstack.h"
int main()
{
	int n;
	stack s;
	init(&s);
	while((scanf("%d", &n) != -1) && !isfull(&s)){
		push(&s, n);
	}
	while(!isempty(&s)){
		n = pop(&s);
		printf("%d\n", n);
	}
	
}
