#include<stdio.h>
#include<stdlib.h>
typedef struct data { 
	char name;   
	struct data *p;
}data; 
data *beginning, *head=NULL, *x, *y;
int main() {
	 int i;
	 x=(data*)malloc(sizeof(data));
	 y=(data*)malloc(sizeof(data));
	 beginning=x;
	 head=y;
	 x->p=y;
	 while(1) {
		i = scanf("%c", &(y->name));
		if(i == -1) { 
			y -> p = beginning;
			break;
		}
		head = y;
		y=(data*)malloc(sizeof(data));
		head -> p = y;
	}
	return 0;
}

