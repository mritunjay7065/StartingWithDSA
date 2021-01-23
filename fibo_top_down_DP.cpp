#include<iostream>
using namespace std;
int fibo(int,int[]);
// TOP - DOWN approach with Memoization
int main()
{
	
	int num = 10,result;
	int a[num+1];       // size of array is num + 1 :)  
	for(int i=0;i<num+1;i++)
		a[i] = -1;       //making array a[num] NULL with -1
	result = fibo(num,a);
	cout<<"fibo(10,a[]) = "<<result;
}

int fibo(int n,int a[])
{  int result;
  if(a[n]!=-1)
	   return a[n];
  else if(n==0)
    result = 0;
  else if(n==1)
	result = 1;
  else
	result = fibo(n-1,a) + fibo(n-2,a);
  a[n] = result ;
  return result;
}
	
	