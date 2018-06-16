#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"


void tinit(tree *t){
	*t = NULL;
}
int count(tree t) {
	if(t == NULL)
		return 0;
	return 1 + count(t->left) + count(t->right);
}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int depth(tree t){
	int x, y;
	if(t == NULL)
		return -1;
	x = depth(t->left);
	y = depth(t->right);
	return 1 + MAX(x, y);	
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
tree copy(tree t){
	node *tmp;
	
	if(t == NULL)
		return NULL;
	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(t->str) + 1);
	strcpy(tmp->str, t->str);	
	tmp->left = copy(t->left);
	tmp->right = copy(t->right);
	return tmp;
}
#define LEFT 100
#define RIGHT 200
void remov(tree *t, char *str){
	node *p, *q, *r, *rp;
	int result;
	int direction;
	/* Locate the node to be deleted + parent */
	p = *t;
	while(p) {
		result = strcmp(p->str, str);
		if(result < 0) {
			q = p;
			p = p->right;
			direction = RIGHT;
		} else if(result > 0){
			q = p;
			p = p->left;
			direction = LEFT;
		} else {
			break;	
		}
	}	
	/* p is the node to be deleted and q is the parent*/	
	if(!p)
		return;
	/* Leaf node : Delete the node, and set parents pointers to nULL
	 */
	if(p->left == p->right) {
		free(p->str);
		free(p);
		if(*t == p) {
			*t = NULL;
			return;	
		}
		if(direction == LEFT)
			q->left = NULL;
		else
			q->right = NULL;
		return;
	}	

	/* Node with one child 
	 *	Delete the node and attach child to grandparent
	 */
	if(p->left != NULL && p->right == NULL) {
		if(direction == LEFT)
			q->left = p->left;
		else
			q->right = p->left;
		free(p->str);
		free(p);
		return;
	}
	if(p->left == NULL && p->right != NULL) {
		if(direction == LEFT)
			q->left = p->right;
		else
			q->right = p->right;
		free(p->str);
		free(p);
		return;
	}
	/* p has two children */
	r = p->right;
	while(r->left) {
		rp = r;
		r = r->left;
	}
	free(p->str); 
	p->str = r->str;
	free(r);
	if(r == p->right)
		p->right = r->right;
	else
		rp->left = r->right;	
}
	
/* N L R */
void preorder(tree t){
	if(t == NULL)
		return;
	printf("%s ", t->str);
	preorder(t->left);	
	preorder(t->right);	
}
void inorder(tree t){
	if(t == NULL)
		return;
	inorder(t->left);	
	printf("%s ", t->str);
	inorder(t->right);	
}
void postorder(tree t){
	if(t == NULL)
		return;
	postorder(t->left);	
	postorder(t->right);	
	printf("%s ", t->str);
}
tree mirror(tree t){
}
void levelwise(tree t){
}
	
