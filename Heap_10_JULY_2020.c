#include<stdio.h>

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void Heapify(int a[],int n)
{
    int pi= (n-1)/2;
    if(a[pi] < a[n])
    {
        swap(&a[pi],&a[n]);
        Heapify(a,pi);
    }

}

void insert(int a[],int num, int n)
{
  a[n]=num;
 Heapify(a,n);
}
void Heapify2(int a[],int sizeheap,int ri)
{  int l = 2*i +1;
    int r= 2*i +2;
    if(a[l] > a[ri])
        { swap(&a[l],&a[ri]);
           Heapify2(a,sizeheap,)
    if(a[r] > a[ri])
            swap(&a[r],&a[ri]);

}
void deleteheap(int a[],int last,int sizeheap)
{
    a[0]=last;
    sizeheap = sizeheap-1;
    Heapify2(a,sizeheap,0);
}





int main()
{
int a[]={21,10,20,7,8,15};
int n=6;
//int num =21;
//insert(a,num,n); //OK
int i;
for(i=0;i<n;i++)
    printf("\na[%d] = %d",i,a[i]);
deleteheap(a,a[n-1],n);

}


