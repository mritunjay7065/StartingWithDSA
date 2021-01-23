#include<stdio.h>
#include<stdlib.h>

struct AVL
{
  int data;
  struct AVL *left;
  struct AVL *right;
};
typedef struct AVL node;
node *root;
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
int findmin(node *root)
 {
   node *r=root;
   while(r->left!=NULL)
  {
   r=r->left;

  }
   return (r->data);
 }
 node * searchNodeBST(node *root,int key)
{
   node *find;
   find=root;
  while(find!=NULL) {

  if(find->data==key)
    {
          return find;
    }
  else if(key > find->data)
      find=find->right;
  else if(key < find->data)
     find=find->left;
  if(find==NULL)
    {     return NULL;
    }
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
void preorder(node *root)
{
    if(root)
    {
        printf(" %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}
node *new_node(int key)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
node * LeftRotation(node *root)   //in case of RR
{
    node *x,*y,*t2;
    x=root;
    y=root->right;
    t2=y->left;
    x->right=t2;
    y->left=x;
    return y;
}
node * RightRotation(node *root)   //in case of LL
{
   node *x,*y,*t2;
   x=root;
   y=root->left;
   t2=y->right;
   x->left=t2;
   y->right=x;
   return y;
}
node *insertintoAVL(node *root,int key)
{
     if(root==NULL)
        return new_node(key);
     else
     {
         if(key < root->data)
             root->left = insertintoAVL(root->left,key);
         else if(key > root->data)
             root->right= insertintoAVL(root->right,key);
     }
    int balance = getbalancefactor(root);

    if(balance > 1 && key < root->left->data)
    {
       // printf("\nIts LL Case so doing RR Rotation\n");
         root= RightRotation(root);
         return root;
    }
     if(balance > 1 && key > root->left->data)
        {
         //   printf("\nIts LR case\n");
            root->left=LeftRotation(root->left);
            root= RightRotation(root);
            return root;
        }
      if(balance < -1 && key > root->right->data)
     {
        // printf("\nIts RR case so doing LL Rotation\n");
         root=LeftRotation(root);
         return root;
     }
      if (balance < -1 && key < root->right->data)
     {
         //printf("\nIts RL case \n");
         root->right=RightRotation(root->right);
         root = LeftRotation(root);
         return root;
     }
return root;
}
node *inorder_successor(node *root)
{

    node *demo =root;
    while(demo->left!=NULL)
    {
        demo=demo->left;
    }
    return demo;
}
node *deletenode(node *root,int val)
{
    if(root==NULL)
        return root;
    if(val < root->data)
        root->left=deletenode(root->left,val);
   else if(val > root->data)
        root->right = deletenode(root->right,val);
    else
    {
      if (root->left ==NULL || root->right ==NULL)
        {
            node *temp=root->left?root->left:root->right;
        if(temp==NULL)
        {
            temp=root;
            root=NULL;
        }
        else
        {
            *root=*temp;
        }
        free(temp);
        }
    else
    {
        node *temp=inorder_successor(root->right);
        root->data =temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    }
    if(root==NULL)
        return root;

       int balance = getbalancefactor(root);

    if(balance > 1 && getbalancefactor(root->left)>=0)
    {
       // printf("\nIts LL Case so doing RR Rotation\n");
         root= RightRotation(root);
         //return root;
    }
     if(balance > 1 && getbalancefactor(root->left)<0)
        {
         //   printf("\nIts LR case\n");
            root->left=LeftRotation(root->left);
            root= RightRotation(root);
          //  return root;
        }
      if(balance < -1 && getbalancefactor(root->right)<=0)
     {
        // printf("\nIts RR case so doing LL Rotation\n");
         root=LeftRotation(root);
        // return root;
     }
      if (balance < -1 && getbalancefactor(root->right)> 0)
     {
         //printf("\nIts RL case \n");
         root->right=RightRotation(root->right);
         root = LeftRotation(root);
        // return root;
     }
     return root;
}


int main()
{   printf("\n----AVL Tree INSERTION Working !!!!!!!!----\n");
      node *root=NULL;
      root=insertintoAVL(root,10);
      root=insertintoAVL(root,7);
      root=insertintoAVL(root,20);
      root=insertintoAVL(root,30);
      root=insertintoAVL(root,25);
       printf("\nInorder : ");inorder(root);printf("\n");
    //  root=insertintoAVL(root,25);
     // root=insertintoAVL(root,81);
      //root=insertintoAVL(root,60);
      printf("\n----AVL Tree DELETION Working !!!!!!----\n");
     // root=insertintoAVL(root,17);
     // root=insertintoAVL(root,18);
    //  displaybalancefactor(root);
      //check(root)
      root= deletenode(root,30);
      //root= deletenode(root,3);
     // root= deletenode(root,35);
      //root= deletenode(root,35);

     printf("\nInorder : ");inorder(root);printf("\n");
      printf("Preorder : ");preorder(root);

}
