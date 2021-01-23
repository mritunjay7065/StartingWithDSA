#include<stdio.h>
#include<stdlib.h>
int * findminmax(int *a,int n)
{
  int i,j,max=a[0],min=a[0],l,m,*p;
for(i=0;i<n;i++)
{
    if(a[i]>=max)
      {max=a[i];
       m=i;}
}
for(j=0;j<n;j++)
{
      if(a[j]<=min)
        {min=a[j];
         l=j;}
}

   p=(int*)malloc(2*sizeof(int));
   p[0]=l;
   p[1]=m;
   return p;
}

void swapminmax(int *a,int n)
{
    int *b;
    b=findminmax(a,n);
  int temp;
  temp=b[0];
  b[0]=b[1];
  b[1]=temp;
  printf("%d is min and %d is max",b[0],b[1]);
}
int sum(int *a,int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
     sum=sum+a[i];
     return sum;
}
void average(int *a, int n)
{
    float s;
    s=sum(a,n)/n;
    printf("\nAverage of array elements is %f \n",s);
}
int find(int *a,int n,int e)
{   int i,m;
    for(i=0;i<n;i++)
    {
        if(a[i]==e)
          {m=i;
         break;
          }
         else
            m=-1;
    }
    return m;

}
void print(int *a,int n)
{  int i;
for(i=0;i<n;i++)
 printf("\n%d\n",a+i);
}

int main()
{
    int i,*a,n,*p,s,e,c;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("\nEnter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   p=findminmax(a,n);
    printf("\n\nthe array indices for min =  %d and for max = %d\n",p[0],p[1]);

    swapminmax(a,n);
    s= sum(a,n);
    printf("\nSum of array is = %d ",s);
    average(a,n);
    printf("Enter the element for search\n");
    scanf("%d",&e);
    printf("\n%d\n",find(a,n,e));
    print(a,n);

}



