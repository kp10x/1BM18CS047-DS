#include<stdio.h>
#include<conio.h>
struct stud
{
    int age;
    char id[10];
    float marks;
} s1[10];
int validate(struct stud s)
{
       if(s.age>20)
         if(s.marks<=100 && s.marks>=0)
            return 1;
         else 
            return 0;

}
int qualify(struct student s)
{
    if(s.marks>=65)
      return 1;
    else 
      return 0;

}
void main()
{
    int n,i;
    clrscr();
    printf("Enter no of students");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    { 
     printf("Enter ID, Age and Marks of Student");
     scanf("%s %d %f",s1[i].ID,&s1[i].age,&s1[i].marks);

     if(validate(s1[i]==1))
       if(qualify(s1[i]==1))
         printf("Student %d is eligible",i+1);
       else
         printf("Student %d is valid but not eligible",i+1);
     else
       printf("Student %d is not valid",i+1);

    }  
    getch();     
}