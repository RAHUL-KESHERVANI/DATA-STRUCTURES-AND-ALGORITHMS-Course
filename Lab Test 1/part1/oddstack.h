#define MAX 32
typedef struct stack{
	int a[MAX];
	int i;
}stack;
int isempty(stack *s);
int isfull(stack *s);
void init(stack *s);
void push(stack *s, int x);
int pop(stack *s);
