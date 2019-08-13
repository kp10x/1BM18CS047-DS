#include<stdio.h>
#include<conio.h>
void push(int s[],int *top,int ele)
{
 if(*top==99)
  {
   printf("Stack Overflow\n");
   return;
  }
 *top=(*top)+1;
 s[*top]=ele;
 return;
}
int pop(int s[],int *top)
{
 int e;
 if(*top==-1)
  {
   printf("Stack Underflow\n");
   return -1;
  }
 e=s[*top];
 *top=(*top)-1;
 return e;
}
void display(int s[],int *top)
{
 int i;
 for(i=*top;i>=0;i--)
   printf("%d\n",s[i]);
}
void main()
{
 int s[100],top=-1;
 int op;
 int sel;
 clrscr();

 do
 {
  printf("Choose an operation to perform:\n");
  printf("1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  scanf("%d",&op);

  switch(op)
  {
   case 1:{
	   int ele;
	   printf("Enter the element to be pushed\n");
	   scanf("%d",&ele);
	   push(s,&top,ele);
	   break;
	  }
   case 2:{
	   int x;
	   x=pop(s,&top);
	   if(x==-1)
	     break;
	   printf("Popped element is %d\n",x);
	   break;
	  }
   case 3:{
	   display(s,&top);
	   break;
	  }
   default: printf("Invalid option\n");
  }
  printf("\nDo you want to continue?(press 1)\n");
  scanf("%d",&sel);
 } while(sel==1);
 getch();
}
