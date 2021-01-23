#include<stdio.h>
void divide(int [],int,int);

int main()
{
int a[] = {5,2,1,3,6,4};
int  n = 6,low,up,mid;
low = 0 ;
up = n-1;
mid = (low + up) / 2 ;
//divide(a,low,up);
divide(a,mid+1,up);
return 0;

}
void divide(int a[],int low,int up)
{
   int mid = (low + up) / 2 ;
   if(low<mid)
   divide(a,low,mid);
   printf("%d ",a[mid]);
}
