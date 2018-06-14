#include<stdio.h>

double power(int x, int y)
{
 long long ans=1;
 long long term=x;
 int sign=0;
 if(y<0)
 {
  y=-y;
  sign=1;
 }
 while(y>0)
 {
  if(y%3==1)
   ans *= term;
  if(y%3==2)
   ans *= term*term;
  term = term * term*term;
  y = y/3;
  }
  if(sign)
   return 1.0/ans;
  return ans;
  }
  
int main(int argc, char *argv[])
{
 int x,y;
 scanf("%d%d",&x,&y);
 printf("%lf\n",power(x,y));
 return 0;
 }
