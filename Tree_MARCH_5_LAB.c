#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
  struct node *left;
  struct node *right;
};
 typedef struct node node;

node *createnode()  //Creating tree function
  {  int x;
     node *new;
     new=(node*)malloc(sizeof(node));
     printf("\nEnter data or press -1 to stop : ");
     scanf("%d",&x);
     if(x==-1)
     return NULL;
     new->data=x;
     printf("\nEnter left child of %d ",x);
     new->left=createnode();
     printf("\nEnter right child of %d ",x);
     new->right=createnode();
      return new;
  }

 void inorder(node *root)     //Inorder
 {
   if(root)
   {
      inorder(root->left);
      printf("%d ",root->data);
      inorder(root->right);
   }
 }
 void postorder(node *root)    //Postorder
 {

    if(root)
    {
      postorder(root->left);
      postorder(root->right);
      printf("%d ",root->data);
    }
  }

 void preorder(node *root)     //preorder
 { if(root)
    {
   printf("%d ",root->data);
   preorder(root->left);
   preorder(root->right);
    }
 }


void deletetree(node *root)
{
  if(root==NULL)
     return;
  deletetree(root->left);
  deletetree(root->right);
 printf("\nDeleting node : %d \n",root->data);
free(root);
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
    root=NULL;
    root=createnode();
  //  printf("\nInoder Traversal is : ");
    //inorder(root);
    printf("\nPostorder Traversal is : ");
    postorder(root);
    search(root,76);
  //  printf("\nPreorder Traversal is : ");
   // preorder(root);
   //printf("\nMaximum in Binary Tree is : %d",findmax(root));
   //printf("\nMinimum in Binary Tree is : %d",findmin(root));
   //deletetree(root);
   // printf("\nNew - Postorder Traversal is : ");
    //postorder(root);
   return 0;
 }

