#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
    int i,j,b[20],k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid &&j<=ub)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
   if(i>mid)
   {
       while(j<=ub)
       {
           b[k]=a[j];
           j++;k++;
       }
   }
   else
   {

       while(i<=mid)
       {
           b[k]=a[i];
           i++;k++;
       }
   }
  for(k=lb;k<=ub;k++)
    a[k]=b[k];
}
void mergesort(int a[],int lb,int ub)
{  int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }

}

int main()
{
    int a[10]={3,-5,1,76,-32,9,65,-12,67,-89};
    int lb=0,ub=10,i;
    mergesort(a,lb,ub);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}
