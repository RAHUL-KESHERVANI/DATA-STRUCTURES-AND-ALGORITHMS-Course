#include<stdio.h>
#include<stdlib.h>
typedef struct data { 
	char name;   
	struct data *p;
}data; 

data *beginning, *head=NULL, *y, *p;
int main() {
	 int i,j = 0;
	 y=(data*)malloc(sizeof(data));
	 beginning=y;
	 p = y;
	 while(1) {
		i = scanf("%c", &(y->name));
		if(i == -1) {
			if(j == 0)
			p = NULL; 
			y -> p = beginning;
			break;
		}
		head = y;
		y=(data*)malloc(sizeof(data));
		head -> p = y;
		j++;
	}
	return 0;
}

