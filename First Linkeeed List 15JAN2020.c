#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int info;
    struct node *link;
};
struct node *START=NULL;
struct node *createnode()
{
   struct node *r;
   r=(struct node*)malloc(sizeof(struct node));
    return r;
}
///FUNCTION FOR Insertion of NODE at the beginning:) :)
void insertnew()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter a number for insertion at STARTING of list\n");
    scanf("%d",&temp->info);

    printf("\n");
    temp->link=START;
    START=temp;
}

void insertnode()///insertion at the end
{
  struct node *temp,*t;
  temp=createnode();
   printf("Enter a number to be entered in the list\n");
   scanf("%d",&temp->info);

   temp->link=NULL;
   if(START==NULL)
        START=temp;
  else
  {
    t=START;
      while(t->link)
      {
          t=t->link;

      }
     t->link=temp;
  }

}
void viewlist()
{  struct node *t;
    if(START==NULL)
    printf("EMPTY LIST");
   else
   {
       t=START;
       while(t)
       {
           printf("%d ",t->info);
           t=t->link;
       }
       printf("\n");

   }

}
void deletenode()///Deletion at the beginning
{    if(START==NULL)
printf("LIST IS EMPTY\n");
else
{
    struct node *t,*d;
     t=START;
     d=t->link;
     free(t);
     START=d;
     printf("\n   NODE DELETED  \n");
}
}
void deletenodelast()///deleting node at last position:) :)
{
   struct node *t,*d;
if(START==NULL)
    printf("List is empty\n");

else
{ t=START;
     while(t->link)
   {   d=t;
       t=t->link;
      //d=t;
   }
   if(t==START)
    START=NULL;
   else
   {  free(t);
       d->link=NULL;
   }

  //d->link=NULL;

}
}
void count()
{  int c=0;
    struct node *t;
    while(t)
    { c++;                           ///COUNT WALA reh gaya hai>>>>
      t=t->link;
    }
    printf("check %d",c);
  //  return c;
}

int main()
{  int d;
    insertnode();
    insertnode();
    insertnode();
    insertnode();

  printf("\nYOUR - LIST\n");
     viewlist();
    deletenodelast();
    printf("your new list \n");
    viewlist();

}
