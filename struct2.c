#include<stdio.h>
#include<conio.h>
struct stud
{
    int age;
    char id[10];
    float marks;
} s1[10];
void main()
{
    int valid=0,n,i;
    clrscr();
    printf("Enter no of students");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    { 
     printf("Enter ID, Age and Marks of Student");
     scanf("%s %d %f",s1[i].ID,&s1[i].age,&s1[i].marks);

     if(s1[i].age>20)
       if(s1[i].marks<=100 && s1[i].marks>=0)
          valid=1;

     if(valid==1 && s1[i].marks>=65)
        printf("Student %d is Eligible",i+1);
    }  
    getch();
         
}