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

/*void deleteBST(node *root,int key)
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

void deleteBST(node *root,int key)
{
  node *find,*curr,*temp,*par;
  find=searchNodeBST(root,key);
  printf("\ndata is = %d,left pointer = %p,right pointer = %p",find->data,find->left,find->right);

 if(find->left == NULL && find->right == NULL)
 {

     curr=find;par=root;
    while(par->left!=curr && par->right!=curr)  //;logic to find parent is absolutely right !!!!!
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
 {

     curr=find;par=root;
      while(par->left!=curr && par->right!=curr)
     {
        if(curr->data < par->data)
            par=par->left;
        else
            par=par->right;
    }
   // parent and curr founded !!!!
 if(curr == par->left)
 {
     if(curr->right!=NULL)
     {
         par->left=curr->right;
         curr->right=NULL;
         free(curr);
     }

   else if(curr->left!=NULL)
   {
       par->left=curr->left;
       curr->left=NULL;
       free(curr);
   }
 }
 else
 {
     if(curr->right!=NULL)
     { par->right = curr->right;
       curr->right=NULL;
       free(curr);
     }
     else
     {
         par->right=curr->left;
         curr->left=NULL;
         free(curr);
     }
  }

 }

 else
 {
   printf("\n   BOTH ARE NOT NULL   \n");
   int d;
   node *temp,*target;
   curr=find;par=root;
   while(par->left!=curr && par->right!=curr)
    {
        if(curr->data < par->data)
            par=par->left;
        else
            par=par->right;
    }
    temp=curr->right;
    d=findmin(temp);
    target=searchNodeBST(temp,d);
    curr->data=d;
    deleteBST(temp,target->data);  //Recursive function to check whether one child or no child for the target node !!!!!!!!!!!!!!!!
 }

}


 /*void heightBSTnode(node *target)
{
    if(target==NULL)
        printf("\nNode is NULL so 0 \n");
    else
    {

  int l=0,r=0;
  node *temp1,*temp2;
  temp1=temp2=target;
  while(temp1->left!=NULL)
  {
      l++;
      temp1=temp1->left;
  }
  while(temp2->right!=NULL)
  {
      r++;
      temp2=temp2->right;
  }

  printf("The height of required node is : %d",l>r?l:r);
    }

} */
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
int main()
{
   node *root=NULL,*find,*target=NULL;
    int ch,key,ele,max,min,value;
    root = insertintoBST(root,45);
    root = insertintoBST(root,25);
    root = insertintoBST(root,3);
    root = insertintoBST(root,35);
    root = insertintoBST(root,74);
    root = insertintoBST(root,70);
    root = insertintoBST(root,60);
    root = insertintoBST(root,81);
   /* root = insertintoBST(root,13);
    root = insertintoBST(root,19);
    root = insertintoBST(root,17);
    root = insertintoBST(root,16);
    root = insertintoBST(root,53);
    root = insertintoBST(root,20);
    root = insertintoBST(root,60);  */


    while(1)
  { printf("\n1.  For Insertion in BST\n2.  For Inorder Tarversal \n3.  Searching a key \n5.  Searching a node \n6.  Maximum key value in BST \n7.  Minimum key value in BST \n8.  Deletion of a given key \n10. Height of a node \n25. For Exit\n");
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
            case 6  :  max= findmax(root);
                       printf("\nThe maximum value in BST is : %d",max);
                       break;

            case 7  :  min = findmin(root);
                       printf("\nThe minimum value in BST is : %d",min);
                       break;

            case 8  :  printf("\nEnter the key value of the node to be deleted : ");
                       scanf("%d",&ele);
                       deleteBST(root,ele);
                       printf("\nInorder    : ");inorder(root);
                       printf("\nPost order : ");
                       postorder(root);
                       printf("\nPreorder   : ");preorder(root);
                       break;
            case 10:   printf("\nEnter data of a node to find its height : ");
                       scanf("%d",&value);
                       target=searchNodeBST(root,value);
                       printf("\nThe height of node is %d \n",findheightBST(target));

                       break;

            case 0 :   printf("______EXITING______\n");
                       exit(0);
                       break;
           default: printf("\nInside Default Case \n");

       }

}
return 0;
}


