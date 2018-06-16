typedef struct node {
	/* The data will be stored in malloced memory
	 * and 'str' will point to it
	 */
	char *str;
	struct node *left, *right;
}node;

typedef node *tree;

