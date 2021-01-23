#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll** create(ll n)
{
	ll i,j;
	ll **arr = (ll**)malloc(n * sizeof(ll*));
	for(i=0;i<n;i++)
	{
	    arr[i] = (ll*)malloc(n * sizeof(ll));
	}
	return arr;
}
ll** spilt(ll **a,ll p,ll q,ll n)
{
	ll i,j;
	ll **b;
	b=create(n/2);
	ll x,y;
	if(p==1&&q==1)
	{
		x=0;
		y=0;
	}
	if(p==1&&q==2)
	{
		x=0;
		y=n/2;
	}
	if(p==2&&q==1)
	{
		x=n/2;
		y=0;
	}
	if(p==2&&q==2)
	{
		x=n/2;
		y=n/2;
	}
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			b[i][j]=a[x+i][y+j];
		}
	}
	return b;
}
ll** addsub(ll **a,ll **b,ll n,int c)
{
	ll **d;
	d=create(n);
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(c==1)
			d[i][j]=a[i][j]+b[i][j];
			if(c==2)
			d[i][j]=a[i][j]-b[i][j];
		}
	}
	return d;
}
ll** combo(ll **a,ll **b,ll **c,ll **d,ll n)
{
	ll i,j;
	ll **x;
	x=create(2*n);
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<2*n;j++)
		{
			if(i<n&&j<n)
			{
				x[i][j]=a[i][j];
			}
			if(i<n&&j>=n)
			{
				x[i][j]=b[i][j-n];
			}
			if(i>=n&&j<n)
			{
				x[i][j]=c[i-n][j];
			}
			if(i>=n&&j>=n)
			{
				x[i][j]=d[i-n][j-n];
			}
		}
	}
	return x;
}
ll** strassen(ll **a,ll **b,int n)
{
	ll **c;
	if(n==1)
	{
		c=create(1);
		c[0][0]=a[0][0]*b[0][0];
		return c;
	}
	ll **a11,**a12,**a21,**a22;
	ll **b11,**b12,**b21,**b22;
	a11=spilt(a,1,1,n);
	a12=spilt(a,1,2,n);
	a21=spilt(a,2,1,n);
	a22=spilt(a,2,2,n);
	b11=spilt(b,1,1,n);
	b12=spilt(b,1,2,n);
	b21=spilt(b,2,1,n);
	b22=spilt(b,2,2,n);

	int x=1,y=2;

	ll **p1,**p2,**p3,**p4,**p5,**p6,**p7;
	p1=strassen(a11,addsub(b12,b22,n/2,y),n/2);
	p2=strassen(addsub(a11,a12,n/2,x),b22,n/2);
	p3=strassen(addsub(a21,a22,n/2,x),b11,n/2);
	p4=strassen(a22,addsub(b21,b11,n/2,y),n/2);
	p5=strassen(addsub(a11,a22,n/2,x),addsub(b11,b22,n/2,x),n/2);
	p6=strassen(addsub(a12,a22,n/2,y),addsub(b21,b22,n/2,x),n/2);
	p7=strassen(addsub(a11,a21,n/2,y),addsub(b11,b12,n/2,x),n/2);

	ll **c11,**c12,**c21,**c22;
	c11=addsub(addsub(p4,p5,n/2,x),addsub(p6,p2,n/2,y),n/2,x);
	c12=addsub(p1,p2,n/2,x);
	c21=addsub(p3,p4,n/2,x);
	c22=addsub(addsub(p1,p5,n/2,x),addsub(p3,p7,n/2,x),n/2,y);

	c=combo(c11,c12,c21,c22,n/2);
	return c;
}
int main()
{
	ll i,j,k,n;
	cout<<"Enter the order of matrix : ";
	cin>>n;
	ll **a,**b,**c;
	 a=create(n);
	 b=create(n);
	cout<<"Enter Matrix 1 : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter Matrix 2 : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];
		}
	}
	c=strassen(a,b,n);
	cout<<"Multiplication gives : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

