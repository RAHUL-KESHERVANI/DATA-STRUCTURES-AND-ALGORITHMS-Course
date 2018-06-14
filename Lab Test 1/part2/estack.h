#define MAX 8
typedef struct stack{
	int *a;
	int i;
}stack;
int isempty(stack *s);
int isfull(stack *s);
void init(stack *s);
void push(stack *s, int x);
int pop(stack *s);
