#include<stdio.h>
//int main()
struct student
{
	int roll;
	char name[50];
};
int main()
{ struct student *ptr,s1;
ptr=&s1;
printf("Address of struture variable s1 is %d\n",&s1);
printf("Address of pointer variable s1 is %d\n",&ptr);
printf("SIZE OF S1 is %d\n",sizeof(s1));
printf("SIZE OF ptr is %d\n",sizeof(ptr->name));
   /*printf("Enter roll number\n");
   scanf("%d",&s1.roll);
   printf("Enter name \n");
   scanf("%s ",&s1.name);
   printf("\n NAME IS : %s",ptr->name);
   printf("\nROLL NUMBER IS : %d",ptr->roll);*/
   return 0;
	
}
