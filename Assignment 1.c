#include<stdio.h>
#include<stdlib.h>
struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
};
typedef struct BST node;
node * insertintoBST(node *root,int key)   ///OK
{
    node *temp,*curr,*p;
    temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;

    if(root==NULL)
       {  root=temp;

          return root;

       }

    else

    {
        curr=root;  ///p is temp pointer to target node(because curr will be NULL at a place) and curr is also pointer to target node
         while(curr)
         {
             p=curr;
        if (key < curr->data)
              curr=curr->left;

         else
              curr=curr->right;

         }   /// p pointer mil gaya !!!

  if(key < p->data)
       p->left=temp;
  else
    p->right=temp;
  }
  return root;

}
void inorder(node *root)   ///OK
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)   ///OK
{
    if(root)
    {    printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)   ///OK
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int findheightBST(node*root)   //OK
{  int x,y;
    if(root==NULL)
     return 0;
    x=findheightBST(root->left);
    y=findheightBST(root->right);
    if(x>=y)
        return (x+1);
    else
        return (y+1);
}

int main()
{   int height;
    node *root = NULL;
    root=insertintoBST(root,8);
    root=insertintoBST(root,3);
    root=insertintoBST(root,1);
    root=insertintoBST(root,6);
    root=insertintoBST(root,4);
    root=insertintoBST(root,7);
    root=insertintoBST(root,10);
    root=insertintoBST(root,14);
    root=insertintoBST(root,13);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPreorder : ");
    preorder(root);
    height =  findheightBST(root);
   printf("Height is  = %d",height);
}
