#include<stdio.h>
int fib(int);
int main()
{

 int n,i;
 printf("\nEnter the number of terms you want to see : ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 printf("%d ",fib(i));
return 0;

}

int fib(int n)
{
    if(n==1)
    return 0;
    else if(n==2||n==3)
    return 1;
    else
    {
        return (fib(n-1) + fib(n-2));
    }

}
