#include"oddstack.h"

int isempty(stack *s){
	return s->i == 0;
}
int isfull(stack *s){
	if(s->i / MAX == 1)
		return 1;
	return 0;
}
void init(stack *s){
	s->i = 0;
}
/* the user should call isfull() before calling push()
*/
void push(stack *s, int x){
	s->a[s->i] = x;
	s->i += 2;
	if((s->i % 2) == 0 && (s->i / MAX)== 1)		//if the even stack index exceeds MAX
		s->i = 1;
}
/* user should check isempty() before calling pop() 
*/
int pop(stack *s){
	int temp;
	if(s->i == 1){
		if(MAX % 2 == 0)
		s->i = MAX;
		else
		s->i = MAX + 1;
	}
	temp = s->a[s->i - 2];
	s->i -= 2;
	return temp;
}
