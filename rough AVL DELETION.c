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
/* node *searchNodeBST(node *root,int key)    //recursive function to search a node
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
*/
/*void searchNodeBST(node *root,int key)
{
   node *find;
   find=root;
  while(find!=NULL) {

  if(find->data==key)
    { printf("\nGiven key found\n");
      return;
    }
  else if(key > find->data)
      find=find->right;
  else if(key < find->data)
     find=find->left;
  if(find==NULL)
    {printf("\nGiven key not found\n");
     return;
     }
 }
 }
 */

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


void searchBST(node *root,int key)    //SEARCHING FOR A KEY using recursion
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

int findmax(node *root)
 {
   node *r=root;
   while(r->right!=NULL)
   {
   r=r->right;
   }
   return (r->data);
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
node * deleteBST(node *root,int key)
{
  node *find,*curr,*temp,*par;
  find=searchNodeBST(root,key);
  printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);
       curr=find;par=root;
       if(find == root)
       {
           int x ;
           x=findmin(root->right);
           curr = deleteBST(curr,x);
           curr->data = x;
         //  curr->right = NULL;
           return root;
       }

 else
{

    while(par->left!=curr && par->right!=curr)  //;logic to find parent is absolutely right !!!!!
    {
        if(curr->data < par->data)
            par=par->left;
        else
            par=par->right;
    }

 if(find->left == NULL && find->right == NULL)
 {

 if(curr->data < par->data)
    par->left=NULL;
 else
    par->right=NULL;
 printf("\nBefore freeing curr , curr->data = %d , curr->left == %p, curr->right == %p",curr->data,curr->left,curr->right);
free(curr);
return root;

 }
 else  if (find->left!= NULL &&find->right == NULL ||find->left == NULL &&find->right!= NULL)
 {
   // parent and curr founded !!!!
 if(curr == par->left)
 {
     if(curr->right!=NULL)
     {
         par->left=curr->right;
         curr->right=NULL;
         free(curr);
         return root;
     }

   else if(curr->left!=NULL)
   {
       par->left=curr->left;
       curr->left=NULL;
       free(curr);
       return root;
   }
 }
 else
 {
     if(curr->right!=NULL)
     { par->right = curr->right;
       curr->right=NULL;
       free(curr);
       return root;
     }
     else
     {
         par->right=curr->left;
         curr->left=NULL;
         free(curr);
         return root;
     }
  }

 }

 else
 {
   printf("\n   BOTH ARE NOT NULL   \n");
   int d;
   node *temp,*target;
    temp=curr->right;
    d=findmin(temp);
  //  target=searchNodeBST(temp,d);
    curr = deleteBST(curr,d);
    curr->data=d;
    curr->right=NULL;
    return root;
 }
}
}



int main()
{
   node *root=NULL,*find,*target=NULL;
   // int ch,key,ele,max,min,value;
    root = insertintoBST(root,45);
    root = insertintoBST(root,25);
    root = insertintoBST(root,3);
    root = insertintoBST(root,35);
    root = insertintoBST(root,74);
    root = insertintoBST(root,70);
    root = insertintoBST(root,60);
    root = insertintoBST(root,81);
    printf("\nInoder traversal is : ");
    inorder(root);printf("\n");
    root = deleteBST(root,45);
    root = deleteBST(root,60);
    printf("\n\nAfter DELETION Inoder traversal is : ");
    inorder(root);printf("\n");
    printf("\n\nAfter DELETION Preoder traversal is : ");
    preorder(root);printf("\n");





return 0;
}


