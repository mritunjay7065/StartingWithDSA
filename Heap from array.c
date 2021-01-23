#include<stdio.h>
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void Heapify(int a[],int i,int n)
{
    int li = 2*i + 1;
    int ri = 2*i + 2;
    int largest = i;
    if(li<=n &&a[li]>a[largest])
        largest =li;
    if(ri<=n &&a[ri]>a[largest])
        largest =ri;
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        Heapify(a,largest,n);
    }
}
int main()
{
   // int a[11]={1,3,5,4,6,13,10,9,8,15,17};
  int a[5]={4,10,3,5,1};
   int  n=4,i;
   for(i=((n-1)/2);i>=0;i--)
   {
       Heapify(a,i,n);
   }
   printf("\nNew Array is :");
   for(i=0;i<5;i++)
    printf("%d ",a[i]);
    printf("\n");
 /* printf("\n Root data is to be deleted i.e., 10\n");
  a[0]=a[4];
  for(i=0;i<4;i++)
    printf("%d ",a[i]);
 n=4;
    for(i=((n-1)/2);i>=0;i--)
   {
       Heapify(a,i,n);
   }
   printf("\nNew : ");
     for(i=0;i<4;i++)
    printf("%d ",a[i]);
    */
printf("\n\nHEAP SORTING.......\n\n");
n=4;
  for(i=n;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        Heapify(a,0,i-1);
    }

    printf("\nNew Array After HeapSort is : ");
   for(i=0;i<5;i++)
    printf("%d ",a[i]);
    printf("\n");

   return 0;

}
