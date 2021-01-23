#include<stdio.h>
#include<stdlib.h>

struct AVL
{
    int data;
    struct AVL *left;
    struct AVL *right;
};
typedef struct AVL node;
node *temp5;
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
  return root;
}
}

void inorder(node *root)
{     if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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
int getbalancefactor(node *root)
{

    return (findheightBST(root->left) - findheightBST(root->right));
}

void displaybalancefactor(node *root)
{
  if(root)
  {
      printf("\nThe Balance Factor of given root->data %d is %d",root->data,getbalancefactor(root));
      displaybalancefactor(root->left);
      displaybalancefactor(root->right);
  }
}
void check(node *root)
{  if(root)
{     int balance = getbalancefactor(root);
    if(balance==0|| balance ==-1||balance ==1)
       printf("\nNo need of balance at  node %d \n",root->data);

    else
         printf("\nNeeds Rotation at node %d \n",root->data);

    check(root->left);
    check(root->right);
    }
    }
    int balance = getbalancefactor(root);
      if(balance==0|| balance ==-1||balance ==1)
       {
           return root;
       }
       else
       {
           if(balance < -1 && root->data < root->right->data)
           {
               printf("\nIts RR case so doing LL Rotation by calling LeftRotator\n");

           }
           if(balance < -1 && root->data < root->right->left->data)
           {
               printf("\nIts RL case so doing RL Rotation\n");
           }
            if(balance > 1 && root->data > root->left->data)
           {
               printf("\nIts LL case so doing RR Rotation\n");
           }
            if(balance > 1 && root->data > root->left->right->data)
           {
               printf("\nIts LR case so doing LR Rotation\n");
           }

       }
       root->left=rotation(root->left);
       root->right=rotation(root->right
int main()
{
    node *root=NULL;
    root=insertintoAVL(root,1);
      root=insertintoAVL(root,2);
      root=insertintoAVL(root,3);
    //  root=insertintoAVL(root,4);
     // root=insertintoAVL(root,5);
     // root=insertintoAVL(root,25);
    //  root=insertintoAVL(root,15);
    //  root=insertintoAVL(root,67);
      check(root);
    displaybalancefactor(root);
    printf("\n\nThe Inorder Traversal is : ");
    inorder(root);printf("\n");
  // root = CheckAndBalance(root);
   // root=insertintoAVL(root,6);
   // root=insertintoAVL(root,7);
   // root=insertintoAVL(root,8);
}
