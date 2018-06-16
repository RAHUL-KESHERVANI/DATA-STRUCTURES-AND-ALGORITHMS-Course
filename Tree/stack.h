
#define MAX 32
typedef struct stack{
	tree a[MAX];
	int i;
}stack;
int isempty(stack *s);
int isfull(stack *s);
void init(stack *s);
void push(stack *s, tree x);
tree pop(stack *s);

