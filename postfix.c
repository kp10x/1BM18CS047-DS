#include<stdio.h>
//#include<math.h>
#include<ctype.h>
void push(int s[],int *top,int a)
{
 if(*top==19)
 {
  printf("Stack Overflow");
  return;
 }
 s[++(*top)]=a;
}
int pop(int s[],int *top)
{
 if(*top==-1)
 {
  printf("Stack Underflow");
  return -1;
 }
 return s[(*top)--];
} 
int res(int op1,int op2,char a)
{
 switch(a)
 {
  case '+': return (op1+op2);
  case '-': return (op1-op2);
  case '*': return (op1*op2);
  case '/': return (op1/op2);
//  case '^': return (pow(op1,op2));
 }
}	         
int main()
{
 int s[20],top=-1,i=0;
 char post[10];
 char symb,num;
 int op1,op2,value,ans;
 printf("Enter the postfix expression:\n");
 scanf("%s",post);
 while(post[i]!='\0')
 {
  symb=post[i]; 
  if(isdigit(symb))
  {
   num=(int)symb-48;
   push(s,&top,num);
  }
  else
  {
   op2=pop(s,&top);
   op1=pop(s,&top);
   value=res(op1,op2,symb);
   push(s,&top,value);
  }
  i++;
 }
 ans=pop(s,&top);
 printf("%d",ans);
 return 1;
 
}   
   
    
