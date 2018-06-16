#include "tree.h"
#include "stack.h"
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i == MAX;	
}
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, tree x) {
	s->a[s->i++] = x;
}
/* the caller should check isempty() before calling pop()..
 */
tree pop(stack *s) {
	tree temp;
	temp = s->a[s->i - 1];
	s->i--;
	return temp;
}

