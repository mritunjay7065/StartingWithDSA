#include<stdio.h>
#include<stdlib.h>
void printarray(int *a,int n)
{  int i;
printf("Your Array\n");
   for(i=0;i<n;i++)
      printf("%d ",*(a+i));
      printf("\n");
}
int *findminmax(int *a,int n)
{
    int i,min=a[0],max=a[0],l,m,*p;
    for(i=0;i<n;i++)
    {   if(a[i+1]>max)
        {  max=a[i];
        //  l=i;   }
        if(a[i+1]<min)
        {  min=a[i];
         // m=i;   }
    }
    //printf("The maximum element of array is = %d and the minimum is = %d\n",max,min);
   // p=(int *)malloc(2*sizeof(int));
 // p[0]=m;
 // p[1]=n;
    return p;

}

int main()
{
    int *a,n,i,*b;
    printf("Enter number of elements\n");
    scanf("%d\n",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printarray(a,n);
   b=findminmax(a,n);
   printf("The indices for the array's min = %d and max = %d",*(b),*(b+1));
    return 0;
}

