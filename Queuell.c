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
NODE insert_rear(NODE head,int item)
{
 NODE p,q;
 p=getnode();
 p->data=item;
 q=head;
 while(q->next!=NULL)
 {
  q=q->next;
 }
 q->next=p;
 p->next=NULL;
 return head;
}
NODE delete_front(NODE head)
{
 NODE p=head;
 if(head==NULL)
  {
   printf("Queue underflow\n");
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
   printf("Queue is empty\n");
   return;
  }
 p=head;
 printf("The linked list contents are:\n");
 while(p!=NULL)
 {
  printf("%d ",p->data);
  p=p->next;
 }
 printf("\n");
}
int main()
{
 int item;
 NODE head=(NODE)malloc(sizeof(struct node));
 printf("Enter the first element\n");
 scanf("%d",&item);
 head->data=item;
 int op,sel=1;
 do
 {
  printf("Choose an operation to perform:\n");
  printf("1.Insert\n");
  printf("2.Delete\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:{
   	   printf("Enter the element to be inserted\n");
   	   scanf("%d",&item);
   	   head=insert_rear(head,item);
   	   break;
   	  } 
   case 2:{
    	   head=delete_front(head);
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
