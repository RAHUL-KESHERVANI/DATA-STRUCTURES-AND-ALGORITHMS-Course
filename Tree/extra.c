#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "stack.h"
// #include "queue.h"

void tinit(tree *t){
	*t = NULL;
}
#define M(a, b) ((a) > (b) ? (a) : (b))
int depth(tree t){
	int x, y;
	if(t == NULL)
		return -1;
	x = depth(t->left);
	y = depth(t->right);
	return 1 + M(x, y);	
}
void insert(tree *t, char *str){
	node *p = *t, *q, *tmp;
	int result;
	while(p) {
		q = p;
		result = strcmp(p->str, str);
		if (result < 0) 
			p = p->right;
		else if (result > 0) 
			p = p->left;
		else
			return;
	}
	/* p is NULL. q is p's parent */
	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	tmp->left = tmp->right = NULL;
	if(*t == NULL) {
		*t = tmp;
		return;
	}
	if(result < 0) 
		q->right = tmp;
	else
		q->left = tmp;
}


char *max(tree t) { /* returns pointer to malloced memory */
	if(t == NULL)
		return "\0";
	char *m, *m1, *m2;
	m = (t)->str;
	m1 = max(t->left);
	m2 = max(t->right);
	if(strcmp(m1, m) > 0)
		m = m1;
	if(strcmp(m2, m) > 0)
		m = m2;
	return m;
}

void preorder_norecur(tree t) {

/* Does a preorder traversal without using recursion. Hint: requires a stack: stack of what? */
	stack tmp;
	init(&tmp);
	tree s;
	printf("preorder\n");
	while(1) {

		while(t != NULL) {
			printf("%s ", t->str);
			if(!isfull(&tmp))
				push(&tmp, t);
			t = t->left;
		}
		if(!isempty(&tmp))
			t = pop(&tmp);
		else
			break;
		t = t->right;
	}
}
/* N L R */
void preorder(tree t){
	if(t == NULL)
		return;
	printf("%s ", t->str);
	preorder(t->left);	
	preorder(t->right);	
}
void printtree(tree t){
	stack s1, s2;
	int space1 = 50, space2 = 40, level = 0, flag = 1, count = 0, flag2 = 0;
	init(&s1);
	init(&s2);
	tree tmp, temp;
	temp = (node *)malloc(sizeof(node));
	temp->str = "\0";
	push(&s1, t);
	int d = depth(t);
	printf("d = %d\n", d);
	while(!isempty(&s1)){
		for (int i = 0; i < space1; ++i)
			printf(" ");
		
		while(count < pow(2, level)){
			tmp = pop(&s1);
			if(tmp->str != "\0"){
				
				printf("%s", tmp->str);
				flag = 1;
			}
			else{
				flag = 0;
				
			}
			if(!d || (!flag && d == level)) {
			printf("kjnk\n");
			// break;
			flag2 = 1;
			}
			else{
				flag2 = 0;
			}
			for (int i = 0; i < space2; ++i)
			{
				printf(" ");
			}
			if(tmp->left != NULL){
				push(&s2, tmp->left);
			}
			else{
				push(&s2, temp);
			}
			if(tmp->right != NULL){
				push(&s2, tmp->right);
			}else{
				push(&s2, temp);
			}
			count++;
		}
		if(flag2){
			break;
		}
		while(!isempty(&s2)){
			// printf("herer\n");
			tmp = pop(&s2);
			push(&s1, tmp);
		}
		space2 /= 2;
		printf("\n");
		
		space1 -= space2/2;
		for (int i = 0; i < space1; ++i)
				printf(" ");
		for(int j = 0; j < pow(2, level);j++){	
			for (int i = 0; i < space2; ++i){
				printf("-");
			}
			for (int i = 0; i < space2; ++i)
				printf(" ");
		}
		printf("\n");
		level++;

	}
}

// void printtree(tree t) {
// 	queue q1, q2;
// 	tree tmp;
// 	int d = 50;
// 	printf("%s\n", t->str);
// 	enq(&q1);
// 	while(!qisempty(&q1)) {
// 		for (int i = 0; i < d; ++i)
// 		{
// 			printf(" ");
// 		}
// 		printf("fda\n");
// 		while(!isempty(&q1)){
// 			tmp = deq(q1);
// 			if(tmp->left != NULL) {
// 				enq(&q2, tmp->left);


// 			}

// 		}



// 		while(!qisempty(&q2)){
// 			tmp = deq(&q2);
// 			enq(q1, tmp);
// 		}
// 	}
// }

int main(){
	char *str;
	tree t;
	tinit(&t);
	while(scanf("%s", str) != -1) {
		insert(&t, str);
		printtree(t);
	}
	preorder_norecur(t);
	printf("\n");
	
	// preorder(t);
	return 0;
}