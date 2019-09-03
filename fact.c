#include<stdio.h>
int fact(int n)
{
 if(n==0)
  return 1;
 return (n*fact(n-1));
}
int main()
{
 int n,f;
 printf("Enter a no to find factorial for:\n");
 scanf("%d",&n);
 f=fact(n);
 printf("Fact is %d",f);
 return 1;
}   
