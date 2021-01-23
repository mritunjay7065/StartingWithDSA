#include<stdio.h>
struct student
{
	int roll;
	char name[50];
	float marks;
};
int main()
{  struct student s1;

printf("Enter roll number \n");
scanf("%d",s1.roll);
printf("Enter name of student\n");
scanf("%s",s1.name);
printf("Enter marks\n");
scanf("%f",s1.marks);
printf("Name is %s\n",s1.name);
printf("Roll number is : %d\n",s1.roll);
printf("marks is : %f",s1.marks);
return 0;
}
	
	
	
	

