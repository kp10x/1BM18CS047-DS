#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
typedef struct node* NODE;
NODE getnode()
{
 NODE p;
 p=(NODE)malloc(sizeof(struct node));
 if(p!=NULL)
   return p;
 else
  {
   printf("Memory not allocated");
   exit(0);
  }
}
NODE push(NODE head,int item)
{
 if(head==NULL)
 {
  head->data=item;
  return head;
 } 
 NODE p;
 p=getnode();
 p->data=item;
 p->next=head;
 head=p;
 return head;
} 
NODE pop(NODE head)
{
 NODE p=head;
 if(head==NULL)
  {
   printf("Stack underflow\n");
   return head;
  }
 printf("Deleted element is %d\n",p->data);
 head=p->next;
 free(p);
 return head;
} 
void display(NODE head)
{
 NODE p;
 if(head==NULL)
  {
   printf("List is empty\n");
   return;
  }
 p=head;
 printf("The linked list contents are:\n");
 while(p!=NULL)
 {
  printf("%d\n",p->data);
  p=p->next;
 }
}
int main()
{
 int item;
 NODE head=(NODE)malloc(sizeof(struct node));
 /*printf("Enter the first element\n");
 scanf("%d",&item);
 head->data=item;*/
 int op,sel=1;
 do
 {
  printf("Choose an operation to perform:\n");
  printf("1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:{
   	   printf("Enter the element to be pushed\n");
   	   scanf("%d",&item);
   	   head=push(head,item);
   	   break;
   	  } 
   case 2:{
    	   head=pop(head);
    	   break;
    	  }
   case 3:{
    	   display(head);
    	   break;
    	  }
   case 4: exit(0);
   default:printf("invalid option\n");
  }
 } 
 while(sel==1);
 return 0;
}  
     

















