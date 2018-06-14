#include<stdio.h>
#include<unistd.h>
#include"list.h"
int main() {
	FILE *fp = fopen("list_file", "r");
	if(fp == NULL)
	printf("error");
	list l;
	init(&l);
	int n;
	while(fscanf(fp, "%d", &n) != -1)
		append(&l, n);
	printf("printing the list in unsorted manner:\n");
	traverse(&l);
	sort(&l);
	printf("printing the list in sorted manner:\n");
	traverse(&l);
	remov(&l, 0);
	printf("printing the list after removal of 0th element:\n");
	traverse(&l);
	n = length(l);
	remov(&l, n);
	printf("printing the list after removal of last element:\n");
	traverse(&l);
	n = length(l);
	remov(&l, n - 1);
	printf("printing the list after removal of 2nd last element:\n");
	traverse(&l);
	remov(&l, 3);
	printf("printing the list after removal of 4th(index 3) last element:\n");
	traverse(&l);
	return 0;
}
