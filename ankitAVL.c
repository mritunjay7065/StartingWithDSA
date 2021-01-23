#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node* nod;
nod root;
void insert(int);
nod search(nod x);
void delete(int);
void inorder(nod);
void postorder(nod);
void preorder(nod);
nod find(nod);
int height(nod);
int balfac(nod);
void rotation(nod);
int typer(nod);
nod check();
int main()
{
	nod y;
	int ch,n,d,x,s;
	while(1)
	{
		printf("Enter the choice : \n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("Enter the number :");
			        scanf("%d",&n);
			        insert(n);
			         break;
			case 2 : printf("Enter the number to be deleted :");
			        scanf("%d",&d);
			        delete(d);
			         break;
			case 3 : printf("Enter choice :\n1.Inorder\n2.Preorder\n3.Postorder\n");
			        scanf("%d",&x);
			        switch(x)
			        {
			        	case 1 : inorder(root);
			        	          printf("\n");
			        	          break;
			        	case 2 : preorder(root);
			                     printf("\n");
			        	         break;
			        	case 3 : postorder(root);
			        	         printf("\n");
			        	          break;
					}
			         break;
			case 4 : exit(1);
			default : printf("Wrong choice !!\n");
		}
	}
}
void insert(int n)
{
nod temp;
	temp=(nod)malloc(sizeof(struct node*));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{    nod p;
		nod curr=root;
		while(curr)
		{
		   p=curr;
		   if(temp->data>curr->data)
		   curr=curr->right;
		   else
		   curr=curr->left;
		}
		if(temp->data>p->data)
		p->right=temp;
		else
		p->left=temp;
	}
	if(root!=temp)
	check(root);
}
nod search(nod x)
{
	 nod y=x;
    while(x->left!=NULL)
    {
        y=x;
    	x=x->left;
	}
	return y;
}
void delete(int n)
{
  nod t=root;
  nod p;
     while(t->data!=n)
    {
        if(t->data>n)
       { p=t;
        t=t->left;
        }
        else
        {  p=t;
           t=t->right;
        }
    }
    if(t->right==NULL&&t->left==NULL)//leaf node
    {
    	if(t==root)// if node is root
    	 root=NULL;
    	if(p->left==t)
    	p->left=NULL;
    	else
    	p->right=NULL;
	}
	else
	{
	  if(t->right==NULL&&t->left!=NULL)//node with leaf at left
	  { if(p->right==t)
	  	p->right=t->left;
	  	else
	  	p->left=t->left;
	  	if(t==root)//if node is root
	  	root=t->left;
	  	t->left=NULL;
	  	free(t);
	  }
	  else
	  {
	  	if(t->left==NULL&&t->right!=NULL) //node with leaf at right
	  	 {   if(p->left==t)
	  		p->left=t->right;
	  		else
	  		p->right=t->right;
	  		if(t==root)//if node is root
	    	root=t->right;
	  		t->right=NULL;
	  		free(t);
		  }
		  else              //node with two leaves
		  {
		  	 nod x,y;
		  	 x=search(t->right);
		  	 y=x->left;
		  	 if(p->left==t)//node at left of parent
		  	 {
		  	 	if(y!=NULL)
		  	    {	t->data=y->data;
		  	 	x->left=NULL;
		  	 	free(y);
		  	    }
		  	 	else
		  	 	{
		  	 		x->left=t->left;
		  	 		p->left=x;
		  	 		t->left=NULL;
		  	 		t->right=NULL;
		  	 		free(t);
				}
			 }
			 else// node at right of parent
			 {
			    if(y!=NULL)
		  	    {	t->data=y->data;
		  	 	x->left=NULL;
		  	 	free(y);
		  	    }
		  	 	else
		  	 	{
		  	 		x->left=t->left;
		  	 		p->right=x;
		  	 		if(t==root)
		  	 		root=x;
		  	 		t->left=NULL;
		  	 		t->right=NULL;
		  	 		free(t);
			 }
		  }
	  }
	}
}
if(root->left||root->right)
	check(root);
}
void inorder(nod t)
{
	if(t==NULL)
	return;
	if(t->left)
	inorder(t->left);
	printf("%d\t",t->data);
	if(t->right)
	inorder(t->right);
}
void preorder(nod t)
{
    if(t==NULL)
    return;
	printf("%d\t",t->data);
	if(t->left)
	preorder(t->left);
	if(t->right)
	preorder(t->right);
}
void postorder(nod t)
{
	 if(t==NULL)
	 return;
	if(t->left)
	postorder(t->left);
	if(t->right)
	postorder(t->right);
	printf("%d\t",t->data);
}
int height(nod x)
{
	if(x==NULL)
	return 0;
	else
	{
		int l=height(x->left);
		int r=height(x->right);

		if(l>r)
		return l+1;
		else
		return r+1;
	}
}
int balfac(nod x)
{
	if(x==NULL)
	return 0;
	int i,j;
	i=height(x->left);
	j=height(x->right);

	return i-j;
}
nod check(nod x)
{
	if(x==NULL)
	return NULL;
	if(balfac(x)==1||balfac(x)==0||balfac(x)==-1)
	{
		x->left=check(x->left);
		x->right=check(x->right);
		return NULL;
	}
	else
	{
	    rotation(x);
	    check(root);
    }
}
int typer(nod x)
{
	int i=balfac(x);
	if(balfac(x->left)==abs(i)-1&&(i>1||i<-1))
	{
		int j=balfac(x->left);
		if(balfac(x->left->left)==abs(j)-1)//   1==LL rotation
		return 1;
		if(balfac(x->left->right)==abs(j)-1)//   3==LR rotation
		return 3;
	}
	if(balfac(x->right)==abs(i)-1&&(i>1||i<-1))
	{
		int j=balfac(x->right);
		if(balfac(x->right->left)==abs(j)-1)//   4==RL rotation
		return 4;
		if(balfac(x->right->right)==abs(j)-1)//  2==RR rotation
		return 2;
	}
}
nod find(nod x)
{
	nod y=root;
	if(x==root)
	return NULL;
	while(y->left!=x||y->right!=x)
	{
		if(y->data>x->data)
		y=y->left;
		else
		y=y->right;
	}
	return y;
}
void rotation(nod x)
{
   int a;
   a=typer(x);
   nod y,z;
   nod p=find(x);
   if(a==1)//   a==1   LL rotation
   {
   	  y=x->left;
   	  z=y->left;
   	  nod q=y->right;
   	  y->right=x;
   	  x->left=q;
   	  if(p==NULL)
   	  root=y;
   	  else
   	  {
   	  	if(p->left==x)
   	  	 p->left=y;
   	  	 else
   	  	 p->right=y;
		 }
   }
   else
   {
   	if(a==2)//   a==2  RR rotation
   	{
   	  y=x->right;
   	  z=y->right;
   	  nod q=y->left;
   	  y->left=x;
   	  x->right=q;
    }
    else
    {
    	if(a==3)//    a==3 LR rotation
    	{
    	   y=x->left;
    	   z=y->right;
    	   nod q=z->left;
    	   z->left=y;
    	   x->left=z;
    	   y->right=q;
    	   q=z->right;
    	   z->right=x;
    	   x->left=q;
    	   if(p==NULL)
   	        root=z;
   	  else
   	  {
   	  	if(p->left==x)
   	  	 p->left=z;
   	  	 else
   	  	 p->right=z;
		 }
		}
		if(a==4)//  a==4  RL rotation
		{
		   	 y=x->right;
    	   z=y->left;
    	   nod q=z->right;
    	   z->right=y;
       	   y->left=q;
    	   q=z->left;
    	   z->left=x;
    	   x->right=q;
    	   if(p==NULL)
   	        root=z;
   	  else
   	  {
   	  	if(p->left==x)
   	  	 p->left=z;
   	  	 else
   	  	 p->right=z;
		 }
		}
	}
   }
}
