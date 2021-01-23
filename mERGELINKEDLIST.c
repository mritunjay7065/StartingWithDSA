#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *head1=NULL,*head2=NULL;
typedef struct node node;
node *createnode()
{
    node *t;
    t=(node*)malloc(sizeof(node));
    return t;
}
void insertnew1()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter a number for insertion at head1ING of list\n");
    scanf("%d",&temp->data);

    printf("\n");
    temp->link=head1;
    head1=temp;
}
void insertnew2()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter a number for insertion at head1ING of list\n");
    scanf("%d",&temp->data);

    printf("\n");
    temp->link=head2;
    head2=temp;
}
void viewlist1()
{  struct node *t;
    if(head1==NULL)
    printf("EMPTY LIST");
   else
   {
       t=head1;
       while(t)
       {
           printf("%d ",t->data);
           t=t->link;
       }
       printf("\n");

   }

}
void viewlist2()
{  struct node *t;
    if(head2==NULL)
    printf("EMPTY LIST");
   else
   {
       t=head2;
       while(t)
       {
           printf("%d ",t->data);
           t=t->link;
       }
       printf("\n");

   }

}
void merge()
{
    node *temp;
    temp=head1;
    while(temp->link)
    {
        temp=temp->link;
    }
  temp->link=head2;

}

int main()
{
 insertnew1();
 insertnew1();
 insertnew1();
 insertnew1();
 printf("\n  List 1\n");
 viewlist1();
 printf("\n List 2 \n");
 insertnew2();
 insertnew2();
 insertnew2();
 insertnew2();
 viewlist2();

 merge();
viewlist1();
 }
