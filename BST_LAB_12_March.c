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
    node *temp,*curr;
    temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;

    if(root==NULL)
       {  root=temp;

          return root;

       }

    else

    {   node *p;
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

void findmax(node *root)
 {
   node *r=root;
   while(r->right!=NULL)
   {
   r=r->right;
   }
   printf("\t  The maximum value in given BST is =  %d\n",r->data);
 }

void findmin(node *root)
 {
   node *r=root;
   while(r->left!=NULL)
  {
   r=r->left;

  }
   printf("\t   The minimum value in given BST is =  %d\n",r->data);
 }

/*void deleteBST(node *root,int key)   //Not working
{
    node *curr,*par;
    curr=root;
  while(curr!=NULL)
  {
      if(key==curr->data)
      {
         break;
      }
    else if(key < curr->data)
    {  par=curr;
       curr=curr->left;
    }

    else
    {
        par=curr;
        curr=curr->right;
    }
   if(curr==NULL)
        printf("\nElement not found\n");

  }   //while loop closing
  printf("\n after while loop \n");
  printf("curr is %p and par is %p and par->right is %p and par->left is %p",curr,par,par->right,par->left);

  if(curr == par->right)
  {
      par->right=NULL;

      //printf("\n affter deletion par->right is %p",par->right);
  }

   else
  {
      par->left=NULL;

  }
  free(curr);
  printf("check\n");
}*/

void deleteBST(node *root,int key)  //NEW DeleteBST() funtion
{
  node *find,*curr,*temp;
  find=searchNodeBST(root,key);
  printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);

 if(find->left == NULL && find->right == NULL)
 {
    node *par;
     curr=find;par=root;
    while(par->left!=curr && par->right!=curr)  //;pgic to find parent is absolutely right !!!!!
    {
        if(curr->data < par->data)
            par=par->left;
        else
            par=par->right;
    }
 if(curr->data < par->data)
    par->left=NULL;
 else
    par->right=NULL;
 printf("\nBefore freeing curr , curr->data = %d , curr->left == %p, curr->right == %p",curr->data,curr->left,curr->right);
free(curr);

 }
 else if (find->left!= NULL &&find->right == NULL ||find->left == NULL &&find->right!= NULL)
 {  printf("\ninside else if \n");

       curr=find;
       printf("dfg\n");
       printf("dfg\n");
       printf("dfg\n");
       printf("dfg\n");
       printf("dfg\n");
       printf("dfg\n");
       printf("dfg\n");

  if(curr->left->data == 0 )
    {
        printf("\nSwap the right of curr with curr->data");

        temp=curr->right;
        curr->data=temp->data;
        curr->right=NULL;
        free(temp);
    }
  else
    { printf("\nSwap the left of curr with curr->data");

      temp = curr->left;
      curr->data= temp->data;
      curr->left=NULL;
      free(temp);
    }
 }

 else
 {
     printf("\n _____--- Both are not NULL______------ ");
 }

}

int main()
{
   node *root=NULL,*find;
    int ch,key,ele;
    while(1)
  { printf("\n1. For Insertion in BST\n2. For Inorder Tarversal \n3. Searching a key \n5. Searching a node \n6. Maximum key value in BST \n7. Minimum key value in BST \n8. Deletion of a given key \n9.  Inorder Successor \n10. Inorder Predecessor \n25. For Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
       {
           case 1  : printf("\nEnter data to enter in BST : ");
                     scanf("%d",&key);
                     root = insertintoBST(root,key);
                     break;
           case 2  :  printf("\n    [Display] \n");
                     printf("\nInorder    : ");
                     inorder(root);
                     printf("\nPost order : ");
                       postorder(root);
                     printf("\nPreorder   : ");preorder(root);
                     printf("\n");
                     break;
           case 25 : printf("______EXITING______\n");
                     exit(0);
                     break;

           case 3  : printf("\nEnter an element for searching(Recursive) : ");
                     scanf("%d",&ele);
                     searchBST(root,ele);
                     break;
         //  case 4  : printf("\nEnter node data  for searching(USING RECURSION) that node : ");
         //            scanf("%d",&ele);
         //            find=searchNodeBST(root,ele);
         //            printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);
         //            break;

            case 5  :  printf("\nEnter node data for searching(Iterative method) : ");
                       scanf("%d",&ele);
                       find= searchNodeBST(root,ele);
                       if(find!=NULL)
                          printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);
                       else
                        printf("\nGiven key node not found\n");
                       break;
            case 6  :  findmax(root);
                       break;

            case 7  :  findmin(root);
                       break;

            case 8  :  printf("\nEnter the key value of the node to be deleted : ");
                       scanf("%d",&ele);
                       deleteBST(root,ele);
                       printf("\nInorder    : ");inorder(root);
                       printf("\nPost order : ");
                       postorder(root);
                       printf("\nPreorder   : ");preorder(root);
                       break;
           // case 9  :




           default: printf("\nInside Default Case \n");

       }

}
return 0;
}

