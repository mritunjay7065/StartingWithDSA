
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *tail=NULL;
void create()
{
    node *n;
    n=(node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d",&n->data);
    n->next=NULL;
   if(tail==NULL)
   {
       tail=n;
       tail->next=n;
   }
   else
   {

       n->next=tail->next;
       tail->next=n;
       tail=n;
   }
}

void display()
{
   printf("\n");
    node *temp;
    if(tail==NULL)
        printf("\nCIRCULAR LIST IS EMPTY\n");
    else
    {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
printf("\n");
}
void insertbeg()
{
    node *n;
     n=(node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d",&n->data);
    n->next=NULL;
    if(tail==NULL)
    {
        tail=n;
        tail->next=n;
    }
    else
    {
    n->next=tail->next;
    tail->next=n;
    }
}
void deletelast()
{
    node *c,*p;
    c=tail->next;
    if(tail==NULL)
      {
          printf("\nList is Empty for deletion\n");

      }
    else
    {

        while(c->next!=tail->next)
        {
            p=c;
            c=c->next;
        }
        p->next=tail->next;
        tail=p;
        free(c);
    }

}
void loopdetect()
{
    node *f,*s;
    s=f=tail->next;
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
   }                          ///closing while loop
}
int main()
{

    create();create();create();create();display();deletelast();display();
    loopdetect();

}
