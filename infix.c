#include<stdio.h>
#include<ctype.h>
int pre(char a)
{
 if(a=='+' || a=='-')
   return 1;
 else if(a=='*' || a=='/')
   return 2;
 else if(a=='^')
   return 3;
 else
   return 0;
}
void push(char s[],int *top,char c)
{
 if(*top==19)
  { printf("Stack Overflow\n");
    return;
  }
 *top=*top+1;
 s[*top]=c;
 return;
}
void pop(char s[],int *top)
{
 if(*top==-1)
 { printf("Stack Underflow\n");
   return;
 }
 if(s[*top]!='(')
   printf("%c",s[*top]);
 *top=*top-1;
 return; 
}  
int main()
{ 
 char s[20];
 int top=-1;
 int i=0;
 char infix[20];
 printf("Enter the infix function\n");
 scanf("%s",infix);
 while(infix[i]!='\0')
 {
  if(isalpha(infix[i])==1)
    printf("%c",infix[i]);
  else if(infix[i]=='(')
    push(s,&top,infix[i]);
  else if(top==-1 || pre(infix[i])>pre(s[top]) || s[top]=='(')
    push(s,&top,infix[i]);
  else if(pre(infix[i])>pre(s[top]))
    pop(s,&top);
  else if(infix[i]==')')
    {
     while(s[top]!='(')
     {
      pop(s,&top);
     }
     pop(s,&top);
    }
  i++;
 }
 while(top!=-1)
 {
  pop(s,&top);
 }
 return 0;
}   
