#include "cstack.h"
int cisempty(cstack *s) {
	return s->i == 0;
}
int cisfull(cstack *s) {
	return s->i == MAX;	
}
void cinit(cstack *s) {
	s->i = 0;
}
void cpush(cstack *s, char x) {
	s->a[s->i++] = x;
}
/* the caller should check isempty() before calling pop()..
 */
char cpop(cstack *s) {
	char temp;
	temp = s->a[s->i - 1];
	s->i--;
	return temp;
}

