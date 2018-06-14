typedef struct node{
	int val;
	struct node* next;
}node;
typedef struct list{
	node *head, *tail;
}list;
void init(list *l);
int length(list l);
void append(list *l, int val);
void traverse(list *l);
int remov(list *l, int pos);
void sort(list* l);

