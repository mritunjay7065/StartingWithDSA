#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next,*prev;
};
struct node* START=NULL;
void insertbeg()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter data \n");
    scanf("%d",&n->info);
    n->next=NULL;
    n->prev=NULL;
    if(START==NULL)
        START=n;
    else
    {
        n->next=START;
        START->prev=n;
        START=n;
 }

}

void printstart()
{
    struct node *t;
    if(START==NULL)
        printf("  \nEMPTY LIST\n");
    else
    {  printf("\nYOUR LIST from starting\n");
         t=START;
         while(t)
         {
             printf("%d ",t->info);
             t=t->next;
         }
   }
      }
void printend()
{
    if(START==NULL)
     printf("\nLIST IS EMPTY\n");
     else
     {   printf("\nYOUR LIST from end\n");
        struct node *t;
         t =START;
        while(t->next)
        {
           t=t->next;
        }
        while(t)
        {

            printf("%d ",t->info);
            t=t->prev;
        }
     }
}
void printlist()
{
  printstart();
  printend();

}


void deletebeg()
{
    struct node *t;
    if(START==NULL)
       printf("\nLIST IS EMPTY\n");
    else
    {
        t=START;
        START=START->next;
        START->prev=NULL;
        free(t);
    }

}

void sorting()
{
   printf("\nLIST SORTED\n");
    struct node *n,*p;
    int temp;
    n=p=START;
    while(p)
    {
       n=p->next;

        while(n)
        {
           if((p->info)>(n->info))
           {
             temp=p->info;
             p->info=n->info;
             n->info=temp;
           }
           n=n->next;
        }

    p=p->next;
    }
}
int main()
{
  int c,i=1;
   while(1)
   {   printf("\nENTER YOUR CHOICE\n");
       scanf("%d",&c);
      switch(c)
      {
          case 1 : insertbeg();
                    break;
          case 2 : printlist();
                    break;
          case 3 : exit(0);
                     break;
          default : printf("WRONG");
                    break;

      }
   }
   /* insertbeg();
    insertbeg();
    insertbeg();
    insertbeg();
    printlist();
    //printend();
   sorting();
    printlist();*/
    return 0;
}
