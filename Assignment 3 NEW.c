#include<stdio.h>
#include<stdlib.h>
int i,j,m,n,p,k;
int **matrix(int m,int n)
{   int **a;

    a=(int**)malloc(m*sizeof(int));
      for(i=0;i<m;i++)
          a[i]=(int*)malloc(n*sizeof(int));
          printf("\nMEMORY ALLOCATED\n");
    return a;
}
int **multiply(int **a,int **b,int m,int n,int p)
{
  int **new;
  new=(int **)malloc(m*sizeof(int));
  for(i=0;i<m;i++)
    new[i]=(int *)malloc(p*sizeof(int));
  printf("\tMEMORY ALLOCATED for resultant matrix\n");
  for(i=0;i<m;i++)
  {
      for(j=0;j<p;j++)
      {
          new[i][j]=0;
          for(k=0;k<n;k++)
            new[i][j]=new[i][j]+a[i][k]*b[k][j];
      }

  }

  return new;
}

int main()
{
    int **z,**x,**y;
    printf("\nEnter no of rows and columns for first matrix \n");
    scanf("%d %d",&m,&n);

    z=matrix(m,n);
printf("\nEnter first array elements\n");
    for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
      scanf("%d",&z[i][j]);}

printf(" \nEnter columns for second matrix\n");
scanf("%d",&p);
x=matrix(n,p);
printf("Enter second array elements\n");
 for(i=0;i<n;i++)
    {for(j=0;j<p;j++)
     scanf("%d",&x[i][j]);}

     y=multiply(z,x,m,n,p);
printf("\tMultiplied Matrix is\n");
      for(i=0;i<m;i++)
    {for(j=0;j<p;j++)
       printf("%d ",y[i][j]);
      printf("\n");
    }


}
