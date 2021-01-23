#include<stdio.h>
int main()
{
  int n,s;
  int r,sum1=0,sum= 0,i,temp1,temp2,count = 0;
   temp1 = n;
  while(n!=0)
  {
    r = temp1%10;
    sum =sum +r;
    temp1=temp1/10;
  }
  if(sum <= s)
    printf("0");
  while(1)
  { if(sum <= s)
       break;
     count++;
     n = n+1;
     temp2=n;
  while(n!=0)
  {
    r = temp2%10;
    sum1 =sum1 +r;
    temp2=temp2/10;
  }
  sum = sum1;
  }
printf("%d ",count);
}
