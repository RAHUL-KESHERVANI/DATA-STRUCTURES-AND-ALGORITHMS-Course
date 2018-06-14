
#define MAX 32
typedef struct cstack{
	char a[MAX];
	int i;
}cstack;
int cisempty(cstack *s);
int cisfull(cstack *s);
void cinit(cstack *s);
void cpush(cstack *s, char x);
char cpop(cstack *s);

