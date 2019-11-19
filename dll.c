#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* next;
 struct node* prev;
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
NODE insert_front(NODE head,int item)
{
 NODE p;
 p=getnode();
 p->data=item;
 p->prev=NULL;
 if(head==NULL)
 {
  p->next=NULL;
  head=p;
 }
 else
 {
  p->next=head;
  head->prev=p;
  head=p;
 }
 return head;
}
NODE insert_left(NODE head,int item,int n)
{
 NODE p=getnode();
 p->data=item;
 if(head->data==n)
 {
  p->next=head;
  head->prev=p;
  p->prev=NULL;
  head=p;
 }
 NODE q=head;
 while(q!=NULL)
 {
  if(q->data==n)
  {
   p->next=q;
   q->prev->next=p;
   p->prev=q->prev;
   p->prev=p;
   return head;
  }
  q=q->next;
 }
}  
NODE delete_val(NODE head,int val)
{
 NODE p=head;
 if(head==NULL)
 {
  printf("List is empty");
  return head;
 }
 if(head->data==val)
 {
  head=head->next;
  free(p);
  return head;
 }
 while(p!=NULL)
 {
  if(p->data==val)
  {
   p->prev->next=p->next;
   p->next->prev=p->prev;
   free(p);
   return head;
  }
  p=p->next;
 }
 printf("Not Found");
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
  printf("%d ",p->data);
  p=p->next;
 }
 printf("\n");
}    
int main()
{
 int item,op;
 NODE head=NULL;
 while(1)
 {
  printf("Choose an option:\n1.Insert\n2.Insert left\n3.Delete value\n4.Display\n5.Exit\n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:{
    	   printf("Enter the element to be inserted\n");
   	   scanf("%d",&item);
   	   head=insert_front(head,item);
   	   break;
   	  }
   case 2:{
    	   int n;
    	   printf("Enter the element and value of a node\n");
   	   scanf("%d %d",&item,&n);
   	   head=insert_left(head,item,n);
   	   break;
   	  }
   case 3:{
    	   int val;
    	   printf("enter value to be deleted\n");
    	   scanf("%d",&val);
    	   head=delete_val(head,val);
    	   break;
    	  }
   case 4:{
   	   display(head);
   	   break;
   	  }
   case 5: exit(0);
   default:printf("Invalid op");
  }
 }
  return 0;
} 
     
 
  
