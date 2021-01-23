#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *head=NULL,*tail=NULL;
void create()
{
    node *n;
    n=(node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d",&n->data);
    n->link=NULL;
    if(head==NULL)
    {
        head=tail=n;
        tail->link=head;///can also USE head->link=n
    }
    else
    {
        tail->link=n;
        tail=n;
        tail->link=head;

    }
}
void display()
{ node *temp=head;
 while(temp!=tail)
 {
     printf("%d",temp->data);
     temp=temp->link;
 }
 printf("%d ",temp->data);  //to print the last element!!!!!!!!!!

}
int main()
{
    create();
    create();
    create();
    create();
    display();

}
