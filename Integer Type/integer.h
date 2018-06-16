typedef struct node
{
	char c;
	struct node *prev;
	struct node *next;
}node;
typedef node Integer;
void initInteger(Integer *a);
void addDigit(Integer *a, char c);
Integer createIntegerFromString(char *str);
Integer addIntegers(Integer a, Integer b);
Integer substractIntegers(Integer a, Integer b);
void printInteger(Integer a);
void destoryInteger(Integer *a);