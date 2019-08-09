#include<stdio.h>
#include<conio.h>
struct stud
{
    int age;
    char id[10];
    float marks;
} s1;
void main()
{
    int valid=0;
    clrscr();
    printf("Enter ID, Age and Marks of Student");
    scanf("%s %d %f",s1.ID,&s1.age,&s1.marks);

    if(s1.age>20)
      if(s1.marks<=100 && s1.marks>=0)
         valid=1;

    if(valid==1 && marks>=65)
       printf("Student is Eligible");
    getch();
           
}