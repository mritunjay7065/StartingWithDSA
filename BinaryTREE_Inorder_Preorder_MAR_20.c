#include<stdio.h>
#include<stdlib.h>

struct BT
{
    int data;
    struct BT *left;
    struct BT *right;
};
typedef struct BT node;
node *find=NULL,*root2=NULL;
int count=0,count2,max;
int flag;

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


void searchBT(node *root, int key)
 {
    if(root!=NULL)
      {
          if(root->data==key)
             { flag==1;
               return;
             }
      searchBT(root->left,key);
      searchBT(root->right,key);
     }//closing root!=NULL
}
void searchNodeBT(node *root,int key)
{
   if(!root)
    return;
  searchNodeBT(root->left,key);
  if(root->data==key)
  {
      find=root;
  }
  searchNodeBT(root->right,key);

}

void countNonLeaf(node *root)
{
  if(root!=NULL)
  {

      if(root->left==NULL&&root->right!=NULL || root->left!=NULL&&root->right==NULL || root->left!=NULL&&root->right!=NULL)
       { count2++;

       }
      countNonLeaf(root->left);
      countNonLeaf(root->right);
  }

}
void countLeaf(node *root)
{
  if(root!=NULL)
  {

      if(root->left==NULL&&root->right==NULL)
       { count++;

       }
      countLeaf(root->left);
      countLeaf(root->right);
  }

}

void printLeafNodes(node *root)
{  countLeaf(root);
   if(count==0)
   {
       printf("No leaf nodes !!!! ");
       return;
   }
 else
  if(root!=NULL)
  {

      if(root->left==NULL&&root->right==NULL)
       { printf("%d ",root->data);

       }
      printLeafNodes(root->left);
      printLeafNodes(root->right);
  }

}

void printNonLeafNodes(node *root)
{
    countNonLeaf(root);
    if(count2!=0)
      if(root!=NULL)
    {

      if(root->left==NULL&&root->right!=NULL || root->left!=NULL&&root->right==NULL || root->left!=NULL&&root->right!=NULL)
       { printf("%d ",root->data);

       }
      printNonLeafNodes(root->left);
      printNonLeafNodes(root->right);
  }

}
void findmax(node *root)
{
    if(root==NULL)
        return;
   // if(root->left)
    findmax(root->left);
    if(max<root->data)
        max=root->data;
    //    if(root->right)
    findmax(root->right);
}

void mirrorBT(node *root)
{
    if(root)
    {
      mirrorBT(root->left);
      mirrorBT(root->right);
      root2=root->left;
      root->left=root->right;
      root->right=root2;
    }


}

int main()
{  node *root,*root2=NULL;
    int in[]={9,5,1,7,2,12,8,4,11,3};
    int pre[]={8,5,9,7,1,12,2,4,11,3};
    int l=sizeof(in)/sizeof(in[0]);
   root= buildtree(in,pre,0,l-1);
   printf("\nInoder traversal of tree is   : ");
   inorder(root);
    printf("\nPreoder traversal of tree is  : ");
   preorder(root);
   printf("\n\n\nThe Value of globally declared flag variable is : %d\n",flag);
 ///  printf("\nPostoder traversal of tree is : ");
  /// postorder(root);
  ///searchBT(root,4);
  ///searchNodeBT(root,5);
///printf("\nContent of *find is : data = %d, left = %p, right = %p",find->data,find->left,find->right);
///countLeaf(root);
///printf("\nNumber of leafNodes of BT are : %d ",count);
///countNonLeaf(root);
///printf("\nNumber of NON_leafNodes of BT are : %d ",count2);
///printf("\nLeaf nodes in INORDER TRAVERSAL is : ");
///printLeafNodes(root);
///printf("\nNON_Leaf nodes in INORDER TRAVERSAL is : ");
///printNonLeafNodes(root);
///findmax(root);

///printf("\nLargest element is %d ",max);
///searchNodeBT(root,max);
///printf("\nContent of *find is : data = %d, left = %p, right = %p",find->data,find->left,find->right);
searchBT(root,8);
   printf("\n\n\nThe Value of globally declared flag variable is : %d\n",flag);
if(flag==1)
    printf("\n   Element Found\n");
else
    printf("\n   Not Found\n");
return 0;
}

