
#include<stdio.h>
#include<stdlib.h>
int m,n,i,j;
int **memory()
{
	int i,j,**a;
//printf("Enter rows and column for matrix\n");
//scanf("%d %d",&m,&n);
a=(int**)malloc(m*sizeof(int));
for(i=0;i<m;i++)
a[i]=(int*)malloc((i+1)*sizeof(int));
	printf("\nMEMORY ALLOCATED SUCCESSFULLY\n");
	
	return a;	
}

void freek(int **z)
{
  for(i=0;i<m;i++)
  {  
    free(z[i]); 
      }
  free(z);
  printf("\nMEMORY FREED\n");
for(i=0;i<m;i++)
{ for(j=0;j<i+1;j++)
     printf("%d ",z[i][j]);
printf("\n");
}
}

int main()
{ 
  int **z,i,j;
  printf("Enetr rows and columns for matrix\n");
  scanf("%d %d",&m,&n);
  z=memory();
for(i=0;i<m;i++)
{ for(j=0;j<i+1;j++)
     scanf("%d",&z[i][j]);
}
for(i=0;i<m;i++)
{ for(j=0;j<i+1;j++)
     printf("%d ",z[i][j]);
printf("\n");
}
freek(z);
return 0;
}

