#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int data;
    struct node *next;

};
struct node *head=NULL;
void printlist(struct node *t)
{
    while(t)
    {
        printf("%d ",t->data);
        t=t->next;

    }
}
int check(struct node *temp,int key)
{  node *t,*m,*l;
 t=temp;
 m=temp;
     int c;
  while(temp)
  {
      if(temp->data==key)
      {
          c=1;
          break;
      }
     else
        c=0;
       temp=temp->next;
  }

return c;
}
void delete(int key)
{   int count=0;
 node *temp;
 temp=head;
       while(temp)
    {
        temp=temp->next;
        count++;
    }
    printf("%d",count);

if(count==key)
{  node *t,*p;
  t=head;
    while(t)
{  p=t;
t=t->next;
}
p->next=NULL;
free(t);
}
   }



int main()
{  int d;
//node *temp;

    int count=0;
   /// node *head=NULL;
    node *second;
    node *third;
    node *fourth;
    ///node *new=NULL;
     head=(struct node*)malloc(sizeof(node));
     second=(struct node*)malloc(sizeof(node));
     third=(struct node*)malloc(sizeof(node));
     fourth=(struct node*)malloc(sizeof(node));
    /// head->data=2;
     ///head->next=second;
     head=second;
     second->data=3;
     second->next=third;
     third->data=5;
     third->next=fourth;
     fourth->data=8;
     fourth->next=NULL;
     printf("\nYOUR LIST\n");

     printlist(head);///INsert a new node after second node
     node *new=NULL;
     new=(struct node*)malloc(sizeof(node));
      new->data=9;
      new->next=third;
      second->next=new;
      printf("\nYOUR NEW LIST WITH INSERTED ELEMENT\n");
       printlist(head);
    d=check(head,9);
if(d==1)
{ printf("\nFOUND\n");
}
else
    printf("\nNOT FOUND\n");
///temp=head;
delete(4);
   printlist(head);


}
