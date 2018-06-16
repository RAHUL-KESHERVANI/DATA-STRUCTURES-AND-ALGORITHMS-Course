#include"integer.h"
#include<stdlib.h>
#include<stdio.h>
void initInteger(Integer *a){
	a->q = NULL;
	a->p = NULL;
	a->i = 0;
}
void addDigit(Integer *a, char c) {
	Integer *t;
	if(c >='0' && c <='9') {
		if(a->i == 0){
			a->i = c - '0';
		}else{
			t = a;
			while(t -> q != NULL){
				t = t -> q;
			} 
			t -> q = (Integer *)malloc(sizeof(Integer));
			t -> q -> p = t;
			t -> q -> q = NULL;
			t -> q -> i = c - '0';
		}

	}
}
int digit(int i, int c, int l){
	int j = i;
	while(l-c >1){
		j/=10;
		l--;
	}
	return j%10;
}
Integer createIntegerFromString(char *str) {
	int count = 0;
	char c;
	Integer t, *a;
	initInteger(&t);
	a = &t;
	while(1){
		c = str[count];
		if(c >='0' && c <='9') {
			if(a->i == 0){
				a->i = c - '0';
			}else{
				while(a -> q != NULL){
					a = a -> q;
				} 
				a -> q = (Integer *)malloc(sizeof(Integer));
				a -> q -> p = a;
				a -> q -> q = NULL;
				a -> q -> i = c - '0';
			}
		}
		else
			break;
		count++;
	}
	return t;
}
Integer addIntegers(Integer a, Integer b) {
	int i = 0, j = 0,h,c = 0,len = 0;
	Integer *t1, *t2,res;
	t1 = &a;
	t2 = &b;
	while(t1 != NULL){
		i = i * 10 + (t1 -> i);
		t1 = t1 -> q;
	}
	while(t2 != NULL){
		j = j * 10 + (t2 -> i);
		t2 = t2 -> q;
	}
	t1 = &res;
	initInteger(&res);
	h = i+j;
	i = h;
	while(i > 0){
		i /= 10;
		len++;
	}
	while(c < len){
		if(c == 0){
			t1 -> i = digit(h, c, len);
		}
		else{
			while(t1 -> q != NULL){
					t1 = t1 -> q;
			} 
			t1 -> q = (Integer *)malloc(sizeof(Integer));
			t1-> q -> p = t1;
			t1 -> q -> q = NULL;
			t1 -> q -> i = digit(h, c, len);
		}
		c++;
	}
	return res;
}
Integer substractIntegers(Integer a, Integer b) {
	int i = 0, j = 0, h, c = 0, len = 0;
	Integer *t1, *t2,result;
	t1 = &a;
	t2 = &b;
	while(t1 != NULL){
		i = i * 10 + (t1 -> i);
		t1 = t1 -> q;
	}
	while(t2 != NULL){
		j = j * 10 + (t2 -> i);
		t2 = t2 -> q;
	}
	if(i > j){
		t1 = &result;
		initInteger(&result);
		h = i - j;
		i = h;
		while(i > 0){
			i /= 10;
			len++;
		}
		while(c < len){
		if(c == 0){
			t1 -> i = digit(h, c, len);
		}
		else{
			while(t1 -> q != NULL){
					t1 = t1 -> q;
			} 
			t1 -> q = (Integer *)malloc(sizeof(Integer));
			t1-> q -> p = t1;
			t1 -> q -> q = NULL;
			t1 -> q -> i = digit(h, c, len);
		}
		c++;
	}
	}
	else{
		result.i = 0;
		result.p =NULL;
		result.q =NULL;
	}
	return result;
}
void printInteger(Integer a) {
	Integer *p;
	p = &a;
	while(p->q != NULL){
		printf("%d",p->i);
		p = p->q;
	}
	printf("%d\n",p->i);
}
void destroyInteger(Integer *a) {
	Integer *t;
	while(a -> q != NULL)
		a = a -> q;
	while(a->p !=NULL){
		t = a->p;
		free(a);
		a = t;
	}
	a -> i = 0;
}
