#include<stdio.h>
#include<stdlib.h>

struct AVL
{
    int data;
    struct AVL *left;
    struct AVL *right;
    int height;
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

node *RightRotation(node *root)
{
        node * x = root;
    node *y = x->left;
    //Tree T1 = y->left;
    node * T2 = y->right;
    //Tree T3 = x->right;
    // Now rotate right
    y->right = x;
    x->left = T2;
    x->height = findheightBST(x);
    y->height = findheightBST(y);
    return root;
}
node *LeftRotation(node *root)
{
    node *temp1,*temp2,*temp3;
    temp1 = root;
    temp2 = root->left;
    temp3 = root->left->right;
    root = temp2;
    root->right = temp1;
    root->right->left = temp3;
    return root;
}

node *PartialRightRotation(node *root)
{   node *temp1,*temp2,*temp3;
    temp1 = root;
    temp2 = root->left;
    temp3 = root->left->right;
    root = temp2;
    root->right =temp1;
    temp1->left=NULL;
    root->right->left=temp3;
    return root;
}
node *PartialLeftRotation(node *root)
{
    node *temp1,*temp2,*temp3;
    temp1= root;
    temp2=root->right;
    temp3 = root->right->left;
    root=temp2;
    root->left = temp1;
    temp1->right=NULL;
    root->left->right = temp3;
    return root;
}
node *insertintoAVL(node *root,int key)
{
    node *temp,*curr,*p;
    temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;
    temp->height=1;  //for leaf node !!!!!!!!!!!!

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
  root->height = findheightBST(root);
  int balance = getbalancefactor(root);
  printf(" \nbalance factor of Root node is %d ",balance);

  if(balance < -1 && key > root->right->data)
  {
      printf("\n\n\n -------------------------its RR case so doing LL rotation ------------\n ");
      root = RightRotation(root);
  }
   if(balance  > 1 && key < root->left->data)
  {
      printf("\n\n\n -------------------------its LL case so doing RR Rotation ------------\n ");
      root = LeftRotation(root);
  }
   if(balance < -1 && key < root->right->data)
  {
      printf("\n\n\n -------------------------its RL case so doing RL Rotation --------------\n");
      root->right = PartialRightRotation(root->right );
        printf("\n\n\ncheck");
      root = RightRotation(root);
  }

   if (balance > 1 && key > root->left->data)
  {
    printf("\n\n\n ---------------------------its LR case so doing LR Rotation ---------------\n");
    root->left= PartialLeftRotation(root->left);
    printf("\n\ncheck 2\n");
    root = LeftRotation(root);
  }


  return root;
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
void preorder(node *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}



int main()
{
    node *root=NULL;
    root=insertintoAVL(root,45);
    root=insertintoAVL(root,70);
    root=insertintoAVL(root,75);
   /* root=insertintoAVL(root,3);
    root=insertintoAVL(root,74);
    root=insertintoAVL(root,25);
    root=insertintoAVL(root,81);
    root=insertintoAVL(root,60); */
    printf("\nInorder Traversal of AVL is : ");
    inorder(root);
    printf("\nPreorder Traversal of AVL is : ");
    preorder(root);
    printf("\n");
/* printf("\nheight of 4 is %d ",findheightBST(root));
 printf("\nheight of 3 is %d ",findheightBST(root->left));
 printf("\nheight of 1 is %d ",findheightBST(root->left->left)); */


}

