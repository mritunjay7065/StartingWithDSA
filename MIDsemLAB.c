#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *head=NULL;    ///Global Head
typedef struct node node;

node *createnode()
{
    node *newnode,*temp;
    newnode=(node*)malloc(sizeof(node));
    return newnode;
}

void printlist()
{
    if(head==NULL)
   {
       printf("\nList is Empty\n");
    return;
    }
  else
  {

    node *temp1,*temp2;
    temp1=head;
    printf("\nForward Print  : ");
    while(temp1)
    {
        printf("%d ",temp1->data);
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\nBackward Print : ");
    while(temp2)
    {
        printf("%d ",temp2->data);
        temp2=temp2->prev;
    }
    printf("\n");
  }
}
/*void insertintolist()
{   node *newnode,*temp;
    newnode=createnode();
    printf("\nEnter data \n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
   if(head==NULL)
   {
       head=newnode;

   }
   else
   {  temp=head;
        while(temp->next)
      {
         temp=temp->next;
      }
    temp->next=newnode;
    newnode->prev=temp;

   }
} */
void enqueue()
 {
    node *temp2,*n;
    n=createnode();
    printf("\nEnter element to Enqueue\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

  if(head==NULL)
   {
       printf("\nList was having no element so added one\n");
                                                      ///Enqueue for only element
       head=n;
   }
  else
  {  temp2=head;              ///Enqueue for more than one element

   while(temp2->next)
   {
       temp2=temp2->next;
   }
  temp2->next=n;
  n->prev=temp2;
  }

}


void dequeue()
{  node *temp1,*temp2;
    if(head==NULL)
    {
        printf("\nUNDERFLOW  cann't Dequeue\n");
        return;
    }
   else if(head->next==NULL&&head->prev==NULL)
   {  temp1=head;
      free(temp1);
      head=NULL;
      printf("\nDequeued the only element\n");
   }
   else
   {
       temp2=head;
       head=head->next;
       head->prev=NULL;
       free(temp2);
       printf("\nSuccessfully Dequeued\n");
   }

}
int isemptyqueue()
{
    if(head==NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    //insertintolist();
  //  printf("isemptyqueue returned : %d\n",isemptyqueue());
  //  dequeue();
    enqueue();enqueue();enqueue();enqueue();
    printlist();
    dequeue();dequeue();dequeue();dequeue();
    printlist();


}
