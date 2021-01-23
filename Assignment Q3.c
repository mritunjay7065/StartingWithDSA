#include<stdio.h>
#include<stdlib.h>

void matrix()
{  int **r,**t;
    int m,n,p;
    int i,j;
    printf("Enter m ,n, p \n");
    scanf("\n%d %d %d",&m,&n,&p);
    r=(int**)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
       r[i]=(int*)malloc(n*sizeof(int));}
    printf("\nEnter first matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&r[i][j]);

        }
    }
    t=(int**)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        t[i]=(int*)malloc(p*sizeof(int));
   printf("\nEnter second matrix\n");
       for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            scanf("%d",&t[i][j]);

        }
    }

  /*      for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {   printf("%d ",r[i][j]);}
        printf("\n");
    }
       for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {   printf("%d ",t[i][j]);}
        printf("\n");
    }
    */
}

int main()
{
    matrix();
}
