#include<stdio.h>
#include<stdlib.h>

struct AVL
{
    int data;
    struct AVL *left;
    struct AVL *right;
};
typedef struct AVL node;
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
int getbalancefactor(node *root)
{

    return (findheightBST(root->left) - findheightBST(root->right));
}
node *insertintoAVL(node *root,int key)
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
        curr=root;
         while(curr)
         { p=curr;
            if (key < curr->data)
              curr=curr->left;
             else
              curr=curr->right;
         }

  if(key < p->data)
       p->left=temp;
  else
    p->right=temp;
  }
  printf("\n The Balance factor for node %d is %d ",root->data,getbalancefactor(root));
  if(getbalancefactor(root)== -1 || getbalancefactor(root)== 1 || getbalancefactor(root)== 0)
      printf("\nno need of rotation\n");
  else
    printf("\nRotation needed\n");
}
void printheight(node *root)
{ if(root!=NULL)
   {
   printf("\nThe height of node %d is %d ",root->data,findheightBST(root));
   printheight(root->left);
   printheight(root->right);
   }
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

int main()
{
    node *root=NULL;
    root=insertintoAVL(root,1);
    root=insertintoAVL(root,2);
    root=insertintoAVL(root,3);
    root=insertintoAVL(root,4);
    root=insertintoAVL(root,5);
    root=insertintoAVL(root,6);
    inorder(root);
    printheight(root);

    return 0;
}




