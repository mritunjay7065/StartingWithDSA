#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=0;
void push(int a)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=a;
    n->link=top;
    top=n;

}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\nUNDER FLOW can't pop\n");
        return;
    }
    else
   {
    printf("\nPopped value is : %d\n",temp->data);
    top=top->link;
    free(temp);
}
}
void display()
{ struct node *temp;
  temp=top;
  if(top==NULL)
  {
      printf("\n   UNDER FLOW \n");
      return;
  }
  else
  {
      while(temp)
      {
          printf(" %d",temp->data);
          temp=temp->link;
      }

  }
}




int main()
{
   // display();
   pop();
   pop();
    push(3);
    push(6);
    push(7);
    display();
    pop();display();
    pop();
    display();
    pop();
    pop();

}
