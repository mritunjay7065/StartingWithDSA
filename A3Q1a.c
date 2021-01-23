#include<stdio.h>
#include<stdlib.h>

void matrixMult(int n,int k,int p,int q,int a[n][k],int b[p][q])
{
    int c[n][q];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            for(int m=0;m<p;m++)
            {
                sum = sum + a[i][m]*b[m][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    printf("\nYour resultant matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int n,k,p,q;
    printf("Enter the rows and columns of first matrix : \t");
    scanf("%d %d",&n,&k);
    int a[n][k];
    printf("\nEnter the rows and columns of second matrix : \t");
    scanf("%d %d",&p,&q);
    printf("\nEnter the elements of the first matrix :\n");
     int b[p][q];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter the elements of the second matrix :\n ");

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    matrixMult(n,k,p,q,a,b);
}


