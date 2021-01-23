#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
  int d;
   struct node *new;
  printf("Enter data or enter -1 to stop\n");
  scanf("%d",&d);
  if(d==-1)
  {
      return NULL;
  }
  else
  {
    new=(struct node *)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    printf("\nEnter the left data for [%d]\n",d);
    new->left=create();
    printf("\nEnter the right data for [%d]\n",d);
    new->right=create();

    return new;
  }
}
void inorder(struct node *root)
{
   if(root==NULL)
   {
       return;
   }
       inorder(root->left);
       printf("%d ",root->data);
       inorder(root->right);

}

/*void inorder(struct node *root)
{
    struct node *t;
    t=root;
   if(t->left)
        inorder(t->left);
   printf("%d ",t->data);
   if(t->right)
    inorder(t->right);


}*/

void insert(struct node *root)
{   int d;
    struct node *t,*p,*curr;
    p=curr=root;
    t=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted\n");
    scanf("%d",&d);
    t->data=d;
    t->left=NULL;
    t->right=NULL;
   if(root==NULL)
   {
       root=t;
       return;

   }
   else
   {
       while(curr)
       { p=curr;
           if(t->data>curr->data)
           {
               curr=curr->right;
           }
           else
            curr=curr->left;
       }///while loop close
   }
     if(t->data>p->data)
        p->right=t;
     else
        p->left=t;
   }
struct node *Findinbst(struct node *root, int data)
{
    if(root==NULL)
    return NULL;
    if(data<root->data)
        return(Findinbst(root->left,data));
    if(data>root->data)
         return(Findinbst(root->right,data));
    return root;
}

int main()
{
    struct node *root=NULL,*temp;
    int data;
    root=create();
    //printf("\nBEFORE INSERTION\n");
    //inorder(root);
    //printf("After INsertion\n");
    //insert(root);
    //inorder(root);
    printf("\nEnter the data for search\n");
    scanf("%d",&data);
   temp=Findinbst(root,data);
   if(temp==NULL)
    printf("Element not found\n");
   else
    printf("\nElement found and the value is %d",temp->data);
  return 0;
}

