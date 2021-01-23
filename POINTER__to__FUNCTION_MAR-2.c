#include<stdio.h>
int f1(int ,int );
int f2(int ,int );

int main()
{
    //int x=4,y=9;
    int (*p)(int,int);
    int (*m)(int,int);
    p=f1;
  printf(" \nCalled f1 function using pointer p  : %d \n",p(8,7));
  m=f2;
  printf(" \nCalled f2 function using pointer m  : %d \n",m(8,7));



}

int f1(int a,int b)
{
    return (a+b);
}
int f2(int a,int b)
{
    return (a*b);
}
