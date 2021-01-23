#include<stdio.h>
///I AM MAKING 3 NODES and traversing IN Singly Linked List(SLL)////YE!!!!!!!!
#include<stdlib.h>
typedef struct node node;
struct node
{
    int data;
    struct node *next;

};
  node *head=NULL;
void sorting()
{
  struct node *p,*c;
  int temp;
  p=head;
  //c=p->next;
  while(p->next)
  {
       c=p->next;
	   while(c)
	   { if(p->data>c->data)
		   {
			   temp=p->data;
			   c->data=p->data;
			   p->data=temp;
		   }
		 c=c->next;
	   }
p=p->next;
  }
  printf("\nLIST SORTED\n");
}

int main()
{

    node *second=NULL;
    node *third=NULL;
    node *fourth,*five;
     head=(struct node*)malloc(sizeof(node));
     second=(struct node*)malloc(sizeof(node));
     third=(struct node*)malloc(sizeof(node));
     fourth=(struct node*)malloc(sizeof(node));
     five=(struct node*)malloc(sizeof(node));


     head->data=2;
     head->next=second;
     second->data=3;
     second->next=third;
     third->data=5;
     third->next=fourth;
     fourth->data=67;
     fourth->next=five;
     five->data=41;
     five->next=NULL;

     node *t;
      t=head;
     while(t)
     {
         printf("%d\t",t->data);
         t=t->next;

     }
     sorting();
       while(t)
     {
         printf("%d\t",t->data);
         t=t->next;

     }

}

