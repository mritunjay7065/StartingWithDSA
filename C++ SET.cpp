#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s;
	int val;
	do{
		
		cout<<"\nEnter element :";
		cin>>val;
		s.insert(val);
		cout<<"Set :";
		for(auto it : s)
		cout<<it<<" ";
		cout<<endl;
	}while(val);
	
}
