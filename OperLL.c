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
NODE insert_front(NODE head,int item)
{
 NODE p;
 p=getnode();
 p->data=item;
 p->next=head;
 head=p;
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
NODE sort(NODE head)
{
 NODE p=head,q;
 int temp;
 while(p->next!=NULL)
 {
  q=p->next;
  while(q!=NULL)
  {
   if(p->data > q->data)
   {
    temp=p->data;
    p->data=q->data;
    q->data=temp;
   }
   q=q->next;
  }
  p=p->next;
 }
 return head;
}     
NODE reverse(NODE head)
{
 NODE curr=head,prev=NULL,temp;
 while(curr!=NULL)
 {
  temp=curr->next;
  curr->next=prev;
  prev=curr;
  curr=temp;
 } 
 head=prev;
 return head;
} 
void concat(NODE head1,NODE head2)
{ 
 NODE p=head1;
 if(head1=NULL)
   return;
 if(head2=NULL)
   return;
 while(p->next!=NULL)
 {
  p=p->next;
 }
 p->next=head2;
}     
int main()
{
 int op,item,n,i;
 NODE head=NULL,otherhead=NULL;
 while(1)
 {
  printf("Choose an option:\n1.Insert\n2.Display\n3.Sort\n4.Reverse\n5.Concatenation\n6.Exit\n");
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
   	   display(head);
   	   break;
   	  }
   case 3:{
    	   head=sort(head);
    	   break;
    	  }
   case 4:{
    	   head=reverse(head);
    	   break;
    	  } 
   case 5:{
   	   printf("Enter number of elements in the second linked list\n");
   	   scanf("%d",&n);
   	   for(i=0;i<n;i++)
   	   {
   	    printf("Enter the element to be inserted\n");
   	    scanf("%d",&item);
   	    otherhead=insert_front(otherhead,item);
   	   }
   	   display(otherhead);
   	   printf("Concatenated list is:\n");
   	   concat(head,otherhead);
   	   display(head);
   	   break; 
   	  } 
   case 6: exit(0);
   default: printf("invalid option");
  }
 }
 return 0;
}       
 
