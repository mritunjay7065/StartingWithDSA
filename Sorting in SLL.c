#include<stdio.h>
#include<stdlib.h>
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
/*void insertnode()
{
 struct node *temp;
 temp=createnode();
 printf("\nEnter info\n");
 scanf("%d",&temp->info);
 temp->next=NULL;
 if(START==NULL)
 {
    START=temp;
 }
 else
 {
     temp->next=START->next;
     START=temp;
 }
}
*/
void insertend()          ///INSERTION AT THE END__-----_____
{  struct node *temp;
temp=createnode();
printf("Enter info\n");
scanf("%d",&temp->info);
temp->next=NULL;
    if(START==NULL)
    {
       START=temp;
    }
    else
    {  struct node *t;
      t=START;
      while(t->next)
      {
          t=t->next; }

          t->next=temp;
    }
}

void printlist()       ///TO PRINT LIST
{   struct node *t;
     if(START==NULL)
{
    printf("\n ----LIST IS EMPTY----\n");

}
else
{
    t=START;
    while(t)
    {
        printf("%d ",t->info);
        t=t->next;
    }
}
}
void sorting()   ///FUNCTION FOR SORTING THE LINKED LIST USING BUBBLE SORT :::::::
{ printf("\nAFTER SORTING\t");
    struct node*c,*p;
    int temp;
    p=START;
    while(p)
    {
        c=p->next;
        while(c)
        {
            if((p->info)>(c->info))
            {
                temp=p->info;
                p->info=c->info;
                c->info=temp;
            }
            c=c->next;
        }

         p=p->next;
    }
}

void reverse()
{ printf("LINKED LIST REVERSED : \t");
struct node *prevnode,*currentnode,*nextnode;
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
{
  insertend();
  insertend();
  insertend();
   insertend();
    insertend();
    printlist();
    printf("\n");
   // sorting();
   //printlist();
 //  reverse();
   //printlist();
   printf("\n Enter an element for the list so that the whole link is sorted\n");
   insertend();
   //printf("\nSORTED LINKED LIST : \n");
   //sorting;
   printlist();
}
