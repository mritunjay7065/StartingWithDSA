#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
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
    printf("Enter a number for insertion at headING of list\n");
    scanf("%d",&temp->data);

    printf("\n");
    temp->next=head;
    head=temp;
}
void printr(node *temp)
{
if(temp==NULL)
    return;
else{
    printr(temp->next);
    printf("%d ",temp->data);
}

}
int main()
{
    insertnew();insertnew();insertnew();insertnew();
    printr(head);
}
