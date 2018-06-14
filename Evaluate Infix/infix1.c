#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stack.h"
#include "cstack.h"
#include <ctype.h>
/* Reads a line of input from the user, till \n
 * and stores it in the array arr and makes arr
 * a string, and returns no. of characters read
 */
int readline(char *arr, int n) {
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n' && i < n)
		arr[i++] = ch;
	arr[i] = '\0';
	return i;
}
#define OPERATOR	100
#define	OPERAND		200
#define	END			300
#define	ERROR		400
typedef struct token{
	int type;
	union data {
		int num;
		char op;
	}data;
}token;

/* input: a infix string, possibly with errors
 * output: the 'next' token from string, separated on 
 *         space or operator
 *  	type: OPERAND, OPERATOR, END, ERROR
 */
enum states {START, DIG, OP, STOP, ERR, SPC};
token getnext(char *str, int *restart) {
	static int i = 0, n1 = 0, n2 = 0;
	int sum = 0;
	token t;
	char ch, ch1;
	if(*restart == 1){
		*restart = 0;
		i = 0;
		n1 = 0;
		n2 = 0;
	}
	while(1){
		ch = str[i];
		ch1 = str[i + 1];
		if(ch >= '0' && ch <='9'){
			sum = sum * 10 + (ch - '0');
			t.type = OPERAND;
			t.data.num = sum;
			if(ch1 == ' ' || ch1 == '-' || ch1 == '*' || ch1 == '/' || ch1 == '%' || ch1 == '+' || ch1 == '(' || ch1 == ')' || ch1 == '\0'){
				n1++;
				i++;
				if(n1 - n2 != 0 && n1 - n2 != 1){
					t.type = ERROR;
				}
				return t;
			}
			
		}
		else if(ch == '+' || ch == '-' || ch == '/' || ch == '%' || ch == '*' ){
			if(ch1 != ' ' && !(ch1 >= '0' && ch1 <='9') && ch1 != '(' && ch1 != ')'){
				t.type = ERROR;
				return t;
			}
			t.type = OPERATOR;
			t.data.op = ch;
			n2++;
			i++;
			if(n1 - n2 != 0 && n1 - n2 != 1){
					t.type = ERROR;
			}
			return t;
		}
		else if(ch =='(' || ch == ')'){
			t.type = OPERATOR;
			t.data.op = ch;
			i++;
			return t;
		}
		else if(ch == '\0'){
			t.type = END;
			return t;
		}
		else if(ch != ' '){
			t.type =ERROR;
			return t;
		}

		i++;
	}
}

char ctop(cstack *s) {
	char temp = '\0';
	if (!cisempty(s))
	{
	 temp = cpop(s);
	cpush(s, temp);
	}
	return temp;
}
/*precedence for operators*/
int precedence(char op) {
	if(op == '%')
		return 70;
	if(op == '*' || op == '/')
		return 50;
	if(op == '+' || op == '-')
		return 30;
	return 0;
}
/*arithmetic operations done on two numbers 
*RETURNS INT_MAX when divisor is 0
*RETURNS INT_MIN when operator is not +, -, *, /, or %
*/
int simple_calc(int a, int b, char op){
	switch(op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '/':
			if(b == 0)
				return INT_MAX;
			return a/b;
		case '*':
			return a*b;
		case '%':
			if(b == 0)
				return INT_MAX;
			return a%b;		
	}
	return INT_MIN;
}

/* Solves infix expression for the operators +,-,*,/,%, with precedence for bracketts...
* USER has to enter SPACE after EVERY number or operator
*/
int infix(char *str){
	stack s;
	cstack cs;
	token t;
	int x, y, restart = 1;
	char ch;
	init(&s);
	cinit(&cs);
	str[strlen(str)] = '\0';
	while(1) {
		t = getnext(str, &restart);
		
		if(t.type == OPERAND) {
			if (!isfull(&s))
			push(&s, t.data.num);
		} 
		else if(t.type == OPERATOR) {
			
			if(t.data.op == '(')
				cpush(&cs, t.data.op);

			else if(t.data.op == ')') {
				ch = cpop(&cs);
				while(ch != '(') {           //keep running until the left bracket is found out 
					if(!isempty(&s))
					x = pop(&s);
					if(!isempty(&s))
					y = pop(&s);
					x = simple_calc(y, x, ch);  // keep calculating the result
					if(x == INT_MAX || x == INT_MIN)
						return x;
					if (!isfull(&s))
					push(&s, x);				// push the result on the integer stack
					ch = cpop(&cs);             // pop the operator from the stack
				}
			}
			
			else{
			//if the stack is empty and precedence of current op is less than the last(top) op 
			while(!cisempty(&cs) && precedence(ctop(&cs)) >= precedence(t.data.op)) {
				if(!isempty(&s))
				x = pop(&s);
				if(!isempty(&s))
				y = pop(&s);
				ch = cpop(&cs);
				x = simple_calc(y, x, ch);  //calculate the last two integers in stack on operator ch 
				if(x == INT_MAX || x == INT_MIN)
						return x;
				if (!isfull(&s))
				push(&s, x);                // and push the result on the integer stack
			}
			
			if (!cisfull(&cs))
			cpush(&cs, t.data.op);            // push the operator on the stack
			
			}
		}
		else if(t.type == END){
			break;
		}
		else if(t.type = ERROR){
			printf("invalid input sum =%d\n", t.data.num);
			return INT_MIN;
		}

	}

	//empties the operator stack in decreasing order of precedence 
	while(!cisempty(&cs)) {
		
		if(!isempty(&s))
		x = pop(&s);
		if(!isempty(&s))
		y = pop(&s);
		ch = cpop(&cs);
		x = simple_calc(y, x, ch);
		if (!isfull(&s))
		push(&s, x);
	}
	return pop(&s);
}


int main(int argc, char *argv[]) {
	char line[128];
	int x, y;
	while(x = readline(line, 128)) {
		y = infix(line);
		if(y == INT_MAX)
			printf("DIVISION BY 0 NOT POSSIBLE\n");
		else if(y != INT_MIN)
				printf("%d\n", y);
	}
	return 0;
}
