#include<stdio.h>
void insertionsort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {   temp=a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
        {
         a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

int main()
{
    int a[8]={21,5,67,12,87,-54,44,22};
    int i;
    insertionsort(a,8);
    for(i=0;i<8;i++)
        printf("%d ",a[i]);

}

