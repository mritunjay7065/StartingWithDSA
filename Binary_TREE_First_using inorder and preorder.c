#include<stdio.h>
#include<stdlib.h>
struct BT
{
    int data;
    struct BT *left;
    struct BT *right;
};
typedef struct BT node;

node *createnode(int data)
{
    node *n=(node *)malloc(sizeof(node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

int search(int in[],int start,int end,int ele)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==ele)
            return i;
    }

}
node *buildtree(int in[],int pre[],int start,int end)
{
    static int preindex=0;
    int index;
    if(start>end)
        return NULL;

    node *tnode=createnode(pre[preindex++]);

    if(start==end)
        return tnode;
    index=search(in,start,end,tnode->data);

   tnode->left=buildtree(in,pre,start,index-1);
   tnode->right=buildtree(in,pre,index+1,end);
   return tnode;
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
    {   printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root)
    {   postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}



void searchBT(node *root,int key)
{
   if(!root)
    return;
  searchBT(root->left,key);
  if(root->data==key)
  {
      printf("\nElement found\n");
  }
  searchBT(root->right,key);

}


int main()
{  node *root;
    int in[]={4,2,5,1,3,6};
    int pre[]={1,2,4,5,3,6};
    int l=sizeof(in)/sizeof(in[0]);
   root= buildtree(in,pre,0,l-1);
   printf("\nInoder traversal of tree is : ");
   inorder(root);
  //  printf("\nPreoder traversal of tree is : ");
  // preorder(root);
   // printf("\nPostoder traversal of tree is : ");
   //postorder(root);
  searchBT(root,4);

}
