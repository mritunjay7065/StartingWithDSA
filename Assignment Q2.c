#include<stdio.h>
#include<stdlib.h>
int **a;
void memory(int **a)
{

    int i,j,m,n;
    printf("Enter no of rows and columns\n");
    scanf("%d %d",&m,&n);
    a=(int*)malloc(m*sizeof(int));
      for(i=0;i<m;i++)
    {     if(i>=n)
          a[i]=(int*)malloc(n*sizeof(int));

      }
          printf("\nMemory Successfully Allocated\n");

    for(i=0;i<m;i++)
    {
         for(j=0;j<n;j++)

    }
}

int main()
{

  memory(a);

}






