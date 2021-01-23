#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *left;
    int data;
    struct node *right;
};
typedef struct node node;
node*create()
{
    int x;
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter data OR Enter -1 for not entering : ");
    scanf("%d",&x);
    if(x==-1)
    {   //free(newnode);
        return NULL;
    }

    printf("\nEnter left child for %d : ",x);
    newnode->left=create();
    printf("\nEnter right child for %d : ",x);
    newnode->right=create();

    return newnode;
}
/*
void preorder(node *root)
{

     if(root!=NULL)
      {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
      }
}*/

void postorder(struct node *root)
{ if(root==NULL)
    {return ;}

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}
void search(node *root,int key)
{
    if(root==NULL)
        return;
    if(root->data==key)
    {
        printf("|Element Found !\n");
        return;
    }
    search(root->left,key);
    search(root->right,key);
}


int main()
{
    node *root;
    root=create();
    int key;
     printf("\nEnter the key to search : ",&key);
  // search(root,key);
   // printf("\nThe Preorder Traversal of Tree is : ");
   // preorder(root);
   printf("\nThe Postorder Traversal of Tree is : ");
    postorder(root);
  printf("\nThe Inorder Traversal of Tree is : ");
    inorder(root);

   return 0;
}


