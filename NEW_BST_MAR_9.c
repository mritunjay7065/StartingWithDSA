#include<stdio.h>
#include<stdlib.h>
struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
};
typedef struct BST node;
node *root;
void insertintoBST(int key)
{
    node *temp,*curr,*p;
    temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;

    if(root==NULL)
       {
           root=temp;
           printf("root==NULL check\n");
       }

    else

    {  printf("\nHERE root is not NULL");
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

    int ch,key;
    while(1)
  { printf("\n1. For Insertion in BST\n2. For Inorder Tarversal \n9. For Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
       {
           case 1 : printf("\nEnter data to enter in BST : ");
                    scanf("%d",&key);
                    insertintoBST(key);
                    break;
           case 9 : printf("\nExiting\n");
                    exit(0);
                    break;
           case 2 :  printf("\nInorder Traversal of BST is : ");
                     inorder(root);

                     break;
           default: printf("\nDEFAULT CASE \n");

       }

}
return 0;
}


