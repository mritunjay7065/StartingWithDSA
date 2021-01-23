#include<stdio.h>
#include<stdlib.h>
struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
};
typedef struct BST node;
node * insertintoBST(node *root,int key)
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

         }/// p pointer mil gaya !!!

  if(key < p->data)
       p->left=temp;
  else
    p->right=temp;
  }
  return root;

}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("\n%d ",root->data);
        inorder(root->right);
    }
}
node *searchNodeBST(node *root,int key)
{  node *find;
    if(root)

    {

        if(root->data==key)
        {
            find=root;
            return find;
        }
        find=searchNodeBST(root->left,key);
        find=searchNodeBST(root->right,key);

    }

}
void searchBST(node *root,int key)
{
    if(root)
    {

    if(root->data==key)
    {
        printf("\nElement Found\n");
        return;
    }
    searchBST(root->left,key);
    searchBST(root->right,key);
    }

}
int main()
{
   node *root=NULL,*find=NULL;
    int ch,key,ele;
    while(1)
  { printf("\n1. For Insertion in BST\n2. For Inorder Tarversal \n3. Searching a key \n4. Searching a node \n10. For Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
       {
           case 1  : printf("\nEnter data to enter in BST : ");
                     scanf("%d",&key);
                     root = insertintoBST(root,key);
                     break;
           case 2  : printf("\nInorder Traversal of BST is : ");
                     inorder(root);
                     printf("\n");
                     break;
           case 10 : printf("\nExiting\n");
                     exit(0);
                     break;

           case 3  : printf("\nEnter an element for searching : ");
                     scanf("%d",&ele);
                     searchBST(root,ele);
                     break;
           case 4  : printf("\nEnter node data  for searching that node : ");
                     scanf("%d",&ele);
                     find=searchNodeBST(root,ele);
                     printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);
                     break;
           default: printf("\nDEFAULT CASE \n");

       }

}
return 0;
}

