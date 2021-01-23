#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,checkN ,checkP ,mul=1;
    int *a;
    scanf("%d",&n);
    a=(int*)malloc(4*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
            for(i=0;i<n;i++)
        printf("%d",a[i]);
   for(i=0;i<n;i++)
    {
        if(a[i]<0)
          checkN = 1 ;
        else
          checkN = 0;
    }

      for(i=0;i<n;i++)
   {
     if(a[i]>0)
            checkP = 1;
        else
            checkP = 0;
   }
if(checkP == 0)
{
    for(i=0;i<n;i++)
    {
        mul = mul * a[i];
    }
   printf("%d",mul);

}
mul = 1;
if(checkN == 0)
{
    for(i=0;i<n;i++)
    {
        mul = mul *a[i];
    }
    printf("%d",mul);

}

    return 0;
}
