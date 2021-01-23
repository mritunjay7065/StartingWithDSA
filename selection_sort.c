#include<stdio.h>
int min(int a[],int k,int n)
{
    int j,loc,MIN;
    MIN=a[k];
    loc=k;
    for(j=k+1;j<=n;j++)
    {
        if(MIN>a[j])
        {
            MIN=a[j];
            loc=j;
        }
    }
        return loc;
}
int main()
{

    int k,temp,n=6,loc;
    int a[]={32,65,1,62,0,76};
    for(k=0;k<=n-2;k++)
    {

        loc=min(a,k,n);
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
    for(k=0;k<n;k++)
        printf("%d ",a[k]);
}
