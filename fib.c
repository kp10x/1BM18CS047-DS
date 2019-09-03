#include<stdio.h>
int fib(int n)
{
 if(n<=1)
  return n; 
 return (fib(n-1) + fib(n-2));
}
int main()
{
 int n,f;
 printf("Enter a no to find fibonacci value for:\n");
 scanf("%d",&n);
 f=fib(n);
 printf("Fibonacci value is %d",f);
 return 1;
} 
