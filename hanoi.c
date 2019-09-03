#include<stdio.h>
void towhanoi(int n,char src,char temp,char dest)
{
 if(n==1)
 {
  printf("Move %d disc from %c to %c\n",n,src,dest);
  return;
 }
 towhanoi(n-1,src,dest,temp);
 printf("Move %d disc from %c to %c\n",n,src,dest);
 towhanoi(n-1,temp,src,dest);
}
int main()
{
 int n;
 printf("Enter no of discs\n");
 scanf("%d",&n);
 towhanoi(n,'A','B','C');
 return 1;
}  
