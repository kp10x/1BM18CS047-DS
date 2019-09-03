#include<stdio.h>
#define SIZE 10
void insert(int q[],int *r,int *f,int item)
{
 if((*f==*r+1)||(*f=0 && *r==SIZE-1))
 {
  printf("Queue Overflow\n");
  return;
 }
 if(*f==-1)
 *r=(*r+1)%SIZE;
 q[*r]=item;
}
int delete(int q[],int *r,int *f)
{
 int item;
 if(*f==-1)
 {
  printf("Queue Underflow\n");
  return -999;
 }
 else
  item=q[*f];
 if(*f==*r)
 {
  *f=-1;
  *r=-1;
 }
 else 
  *f=(*f+1)%SIZE;
 return item;
}
void display(int q[],int r,int f)
{
 int i;
 if(f>r)
 {
  printf("Queue is empty\n");
  return;
 }
 printf("Contents of the queue are:\n");
 for(i=f;i<=r;i=(i+1)%SIZE)
  printf("%d ",q[i]);
}
int main()
{
 int f=-1,r=-1;
 int q[SIZE];
 int op,sel;
 do
 {
  printf("Choose an operation to perform:\n");
  printf("1.Insert\n");
  printf("2.Delete\n");
  printf("3.Display\n");
  scanf("%d",&op);

  switch(op)
  {
   case 1:{
	   int item;
	   printf("Enter the element to be inserted\n");
	   scanf("%d",&item);
	   insert(q,&r,&f,item);
	   break;
	  }
   case 2:{
	   int x;
	   x=delete(q,&r,&f);
	   if(x==-999)
	     break;
	   printf("Deleted element is %d\n",x);
	   break;
	  }
   case 3:{
	   display(q,r,f);
	   break;
	  }
   default: printf("Invalid option\n");
  }
  printf("\nDo you want to continue?(press 1)\n");
  scanf("%d",&sel);
 } while(sel==1);
 return 1;
}     
    
