
#include<stdlib.h>
#include<stdio.h>
#include"integer.h"
int main() {
    Integer a, b, c;
    char ch;
    char str[64]; /* This size may change */

    initInteger(&a);
    initInteger(&b);

    while((ch = getchar()) != '\n')
        addDigit(&a, ch);
    scanf("%s", str);
    b = createIntegerFromString(str);
    c = addIntegers(a, b); 
    printInteger(c);
    // destoryInteger(&c);
    c = substractIntegers(a, b);
    printInteger(c);
    // destoryInteger(&c);
}
