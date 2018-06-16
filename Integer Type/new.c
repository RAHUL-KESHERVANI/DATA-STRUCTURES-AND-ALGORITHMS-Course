#include"integer.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
/* Initialize the "Integer" type data structure. 
 * You may interpret an "empty" Integer to be the value 0. 
 */

void initInteger(Integer *a){
	a->prev = a->next = NULL;
	a->c = '0';
} 

/* Appends one digit to an existing Integer data type. 
 * E.g. if the Integer a was 1234 and the function was called as
 * addDigit(Integer *a, char c); where c='5' 
 * then Integer a becomes 12345. 
 * Ignore the request if c is not a digit.  
 */

void addDigit(Integer *a, char c){
	if(isdigit(c)){
		
		if(a->c == '0'){
			a->c = c;
			return;
		}
		node *p = a;
		node *t = (node *)malloc(sizeof(node));
		t->c = c;
		while(p->next != NULL){
			p = p->next;		
		}
		t->prev = p;
		t->next = NULL;
		p->next = t;
		
	}
} 

/* Create and return an Integer from a string. 
 * 'str' may contain non-digits, in that case you should
 * process 'str' upto the first non-digit. E.g. if 
 * 'str' was  123ab45 then the Integer returned will be 123
 * if 'str' was "abhijit" then the Integer returned will be 0
 */

Integer createIntegerFromString(char *str){
	Integer a, *p;
	initInteger(&a);
	int i = 1;
	if(str[0] != '\0')
		a.c = str[0];
	p = &a;
	while(str[i] != '\0'){
		p->next = (node *)malloc(sizeof(node));
		p->next->c = str[i];
		p->next->next = NULL;
		p->next->prev = p;
		p = p->next;
		i++;
	}
	return a;
}

/* This function adds two Integers a and b, and returns the sum as Integer */
#define changeToInt(c) c - '0' 
Integer addIntegers(Integer a, Integer b){
	int i = 0, j = 0;
	Integer  *p = &a, *q = &b, *c;
	while(p->next != NULL){
		p = p->next;
	}
	while(q->next != NULL){
		q = q->next;	
	}
	c = (node *)malloc(sizeof(node));
	c->next = c->prev = NULL;
	c->c = '0';
	i = changeToInt(p->c) + changeToInt(q->c);
	if(i < 10){
			c->c +=  i;
	}else{
		c->prev = (node *)malloc(sizeof(node));
		c->prev->c = '1';
		c->prev->next = c;
		c->prev->prev = NULL;
		c->c += i - 10;
	}
	p = p->prev;
	q = q->prev;
	while((p != NULL && q != NULL)){
		i = changeToInt(p->c) + changeToInt(q->c);
		if(c->prev == NULL){	
			//for the case where there is no prev node
			if(i < 10){
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '0' + i;
				c->prev->next = c;
				c->prev->prev = NULL;
				c = c->prev;	
			}else{
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '0' + i - 10;
				c->prev->next = c;
				c->prev->prev = (node *)malloc(sizeof(node));
				c->prev->prev->prev = NULL;
				c->prev->prev->next = c->prev;
				c->prev->prev->c = '1';
				c = c->prev;
			}
		}else{
			c = c->prev;
			if(i < 9){
				c->c += i;
			}
			else{
				c->c += i - 10;
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '1';
				c->prev->prev = NULL;
				c->prev->next = c;
			}
		}

		p = p->prev;
		q = q->prev;
		j++;
	}
	if(p == NULL){
		if(q != NULL){
			p = q;
		}else{
			if(c->prev != NULL){
				c = c->prev;
			}
			return *c;
		}
	}
	while(p != NULL){
		i = changeToInt(p->c); 
		if(c->prev == NULL){	
			//for the case where there is no prev node
			if(i < 10){
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '0' + i;
				c->prev->next = c;
				c->prev->prev = NULL;
				c = c->prev;	
			}else{
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '0' + i - 10;
				c->prev->next = c;
				c->prev->prev = (node *)malloc(sizeof(node));
				c->prev->prev->prev = NULL;
				c->prev->prev->next = c->prev;
				c->prev->prev->c = '1';
				c = c->prev;
			}
		}else{
			c = c->prev;
			if(i < 9){
				c->c += i;
			}
			else{
				c->c += i - 10;
				c->prev = (node *)malloc(sizeof(node));
				c->prev->c = '1';
				c->prev->prev = NULL;
				c->prev->next = c;
			}
		}
		p = p->prev;
	}
	if(c->prev != NULL)
		c = c->prev;
	return *c;
}

/* This function substracts two Integers a and b, and returns the difference as Integer. Here a must be bigger than b (as Integer is non-zero). If a is smaller than b, then you can return an Integer with value 0 */

Integer substractIntegers(Integer a, Integer b){
	Integer *p = &a, *q = &b, *r, *t1, *t2;
	int i = 1, j = 1;
	r = (node *)malloc(sizeof(node));
	r->c = '0';
	r->prev = r->next = NULL;
	while(p->next != NULL){
		p = p->next;
		i++;
	}
	while(q->next != NULL){
		q=  q->next;
		j++;
	}
	if(i < j){
		return *r;
	}
	// else if(i == j){
	// 	t1 = p, t2 = q;
	// 	while(t1->prev != NULL){
	// 		if(t1->c < t2->c)
	// 			return c;	
	// 		t1 = t1->prev;
	// 	}
	// }

	i = p->c - q->c;
	// printf("i = %d\n", i);
	if(i < 0){
		r->c += i + 10;
		r->prev = (node *)malloc(sizeof(node));
		r->prev->c = 's';
		r->prev->prev = NULL;
		r->prev->next = r;
	}else{
		r->c += i;
	}
	p = p->prev;
	q = q->prev;
	while(p != NULL && q != NULL){

		i = p->c - q->c;
		printf("i = ====%d\n", i);
		if(r->prev == NULL){
			if(i < 0){
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = '0' + i + 10;
				r->prev->prev = NULL;
				r->prev->next = r;
				r->prev->prev = (node *)malloc(sizeof(node));
				r->prev->prev->c = 's';
				r->prev->prev->prev = NULL;
				r->prev->prev->next = r->prev;
				r = r->prev;
			}else{
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = '0' + i;
				r->prev->prev = NULL;
				r->prev->next = r;
				r = r->prev;
			}
		}else{
			if(i > 0){
				r = r->prev;
				r->c = '0' + i - 1;
			}
			else{
				r = r->prev;
				r->c = '0' + (9 + i);
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = 's';
				r->prev->prev = NULL;
				r->prev->next = r;
			}
		}
		p = p->prev;
		q = q->prev;
	}
	while(p != NULL){
		i = p->c - '0';
		// printf("%d\n", i);
		if(r->prev == NULL){
			if(i < 0){
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = '0' + i + 10;
				r->prev->prev = NULL;
				r->prev->next = r;
				r->prev->prev = (node *)malloc(sizeof(node));
				r->prev->prev->c = 's';
				r->prev->prev->prev = NULL;
				r->prev->prev->next = r->prev;
				r = r->prev;
			}else{
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = '0' + i;
				r->prev->prev = NULL;
				r->prev->next = r;
				r = r->prev;
			}
		}else{
			if(i > 0){
				r = r->prev;
				r->c = '0' + i - 1;
			}
			else{
				r = r->prev;
				r->c = '0' + (9 + i);
				r->prev = (node *)malloc(sizeof(node));
				r->prev->c = 's';
				r->prev->prev = NULL;
				r->prev->next = r;
			}
		}
		p = p->prev;
	}
	// if(r->prev != NULL){
	// 	printf("sfdfdsdfssddsfds\n");
	// 	r = r->prev;
	// }
	return *r;
}

/* Print an Integer (just the sequence of digits, nothing else) with a \n in the end  */

void printInteger(Integer a){
	Integer *t = &a;
	// printf("fdsf\n");
	while(t != NULL){
		printf("%c", t->c);
		t = t->next;
	}
	printf("\n");
}

/* Destroys an Integer, i.e. deallocates all malloced memory 
 * for the Integer and reInitiatizes it */

void destroyInteger(Integer *a){
	node *p;
	while(a != NULL){
		p = a->next;
		free(a);
		a = p;
	}
}





int main() {
    Integer a, b, c;
    char ch;
    char str[64]; /* This size may change */

    initInteger(&a);
    initInteger(&b);

    while((ch = getchar()) != '\n')
        addDigit(&a, ch);
    while((ch = getchar()) != '\n')
        addDigit(&b, ch);
    // printf("testing\n");
    
    // scanf("%s", str);
    // b= createIntegerFromString(str);
    printInteger(a);
    printInteger(b);
    // b = 
    // c = addIntegers(a, b);
    // printInteger(c);
    // destroyInteger(&c);
    c = substractIntegers(a, b);
    printInteger(c);
    // destroyInteger(&c);
}
