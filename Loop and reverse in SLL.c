#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int info;
    struct node *next;
};
struct node *START=NULL;
struct node *createnode()
{
   struct node *r;
   r=(struct node*)malloc(sizeof(struct node));
    return r;
}
void insertnode()///insertion at the end
{
  struct node *temp,*t;
  temp=createnode();
   printf("Enter a number to be entered in the list\n");
   scanf("%d",&temp->info);

   temp->next=NULL;
   if(START==NULL)
        START=temp;
  else
  {
    t=START;
      while(t->next)
      {
          t=t->next;

      }
     t->next=temp;
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
           t=t->next;
       }
       printf("\n");

   }

}
void loopdetect()
{
    node *f,*s;
    s=f=START;
    while(s&&f&&f->next)
    {
      s=s->next;
       f=f->next->next;
    if(s==f)
    {
        printf("LOOP DETECTED \n");
        break;
    }
    if(s==NULL||f==NULL||f->next==NULL)
    {
        printf("Loop Not Detected\n");
        break;
    }
}
}
void reverse()
{  printf("\nLIST REVERSED\n");
    node *prevnode,*currentnode,*nextnode;
    prevnode=NULL;
    currentnode=nextnode=START;
    while(nextnode)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
START=prevnode;

}
int main()
{  int d;
    insertnode();
    insertnode();
    insertnode();
    insertnode();
    insertnode();
    loopdetect();
  printf("\nYOUR LIST : ");
     viewlist();
     reverse();
     viewlist();
}
