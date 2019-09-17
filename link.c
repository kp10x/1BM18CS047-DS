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
void insert_pos(NODE head,int item,int pos)
{
 NODE curr,prev=NULL,p;
 int count=1;
 p=getnode();
 p->data=item;
 p->next=NULL;
 if(head==NULL)
 {
  if(pos==1)
    return;
  else
   {
    printf("Invalid");
    return;
   }
  if(pos==1)
  {
   p->next=head;
   head=p;
  }
  else
  {
   curr=head;
   while(curr!=NULL && count!=pos)
   {
    prev=curr;
    curr=curr->next;
    count++;
   }
   if(count==pos)
    {
     prev->next=p;
     p->next=curr;
    }
   else
     printf("Invalid postion");
  }         
 }
} 
void insert_end(NODE head,int item)
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
}
int main()
{
 NODE head=(NODE)malloc(sizeof(struct node));
 int op,sel;
 do
 {
  printf("Choose an operation to perform:\n");
  printf("1.Insert front\n");
  printf("2.Insert at postion\n");
  printf("3.Insert end\n");
  printf("4.Display\n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:{int item;
   	   printf("Enter the element to be inserted\n");
   	   scanf("%d",&item);
   	   head=insert_front(head,item);
   	   break;
   	  } 
   case 2:{int item,pos;
   	   printf("Enter the element to be inserted and postion\n");
   	   scanf("%d %d",&item,&pos);
   	   insert_pos(head,item,pos);
   	   break;
   	  } 
   case 3:{int item;
   	   printf("Enter the element to be inserted");
   	   scanf("%d",&item);
   	   insert_end(head,item);
   	   break;
   	  }  
   case 4:{display(head);
   	   break;
   	  } 
   default: printf("Invalid option\n");
  }
  printf("Do you want to continue?(press 1)\n");
  scanf("%d",&sel);
 }while(sel==1);
 return 0;
}             
