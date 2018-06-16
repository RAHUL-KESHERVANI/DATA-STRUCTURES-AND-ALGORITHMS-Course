#define N 6 
typedef struct queue {
	char data[N][16];
	int f, r, count;
}queue;

void qinit(queue *q);
void enq(queue *q, char *str); 
char *deq(queue *q);
int qempty(queue *q);
int qfull(queue *q);
