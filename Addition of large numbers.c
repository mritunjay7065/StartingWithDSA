#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *insertend(node *head,int data)
{
    node * n;
    n=(node*)malloc(sizeof(node));
    n->data =data;
    n->next =NULL;
    if(head == NULL)
       {  head = n;
          return head;}
    else
    {
        node *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = n;
        return head;
    }

}

node *insertBeg(node *head, int data)
{
    node *n;
    n =(node *)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if(head==NULL)
    { head = n;
      return head;
    }
    else
    {
        node *temp;
        temp =head;
        head = n;
        n->next = temp;
        return head;
    }

}

void printlist(node *head)
{
    if(head == NULL)
        printf("\nEMPTY\n");
    else
    {
      node *temp;
     temp =head;
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }

}
}

int main()
{   int res,carry;
    node *head1 = NULL,*head2 =NULL,*head3 = NULL;
    node *temp1,*temp2;
    head1 = insertBeg(head1,3);
    head1 = insertBeg(head1,4);
    head1 = insertBeg(head1,9);
    head1 = insertBeg(head1,1);
    printf("\n List 1 is : ");
    printlist(head1);
    head2 = insertBeg(head2,7);
    head2 = insertBeg(head2,4);
    head2 = insertBeg(head2,1);
  //  head2 = insertBeg(head2,9);
    printf("\n List 2 is : ");
    printlist(head2);
    temp1= head1;
    temp2=head2;
    while(temp1!=NULL || temp2!=NULL)
    {   res = temp1->data + temp2->data;
           carry = res/10;
             if(carry !=0)
               res = res%10;
      head3 = insertBeg(head3,res);
      printf(" head3->data = %d ",head3->data);
      temp2->next->data =temp2->next->data + carry;
      temp1=temp1->next;
      temp2=temp2->next;
    }

}
