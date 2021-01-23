#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *head=NULL;
void createnode()
{
    node *temp,*n;
    int i,m;
    n=(node*)malloc(sizeof(node));
    printf("\nHow many data to enter in CLL\n" );
    scanf("%d",&m);
    for(i=1;i<=m;i++)
   {
    printf("\nEnter the data\n");
    scanf("%d",&n->data);
    n->link=NULL;
    if(head==NULL)
    {
        head=n=temp;

    }
    else
    {
        temp->link=n;
        temp=n;
    }
   }

}
void display()
{
    node *t;
    if(head==NULL)
    printf("\nList is Empty{DISPLAY FN}\n");
    else
    {
       t=head;

      // t=t->link;
       while(t!=head)
       {
           printf("%d ",t->data);
           t=t->link;
       }
        printf("%d ",t->data);
    }

}
int main()
{
    createnode();createnode();createnode();createnode();createnode();
    display();
}
