#include<iostream>
#include<queue>
using namespace std;
int main()
{
int A[6][6] = {{0,1,1,1,0,0},{1,0,0,0,1,1},{1,0,0,0,0,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,1,1,0,0,0}};
int i,j;
for(i=0;i<7;i++)
{   cout<<" " <<i<<" row "<<endl;
    for(j=0;j<7;j++)
       {
           cout<<A[i][j]<<" ";
       }
    cout<<endl;
}
cout<<A[6][3];
/*
int sourceNode = 0 ;
queue<int> s;
cout<<"\n0\n";
visited[0] = 1 ;
for(i=0;i<4;i++)
{  cout<<"Adjacent nodes of "<<i<<" are : ";
    for(j=0;j<4;j++)
    {
        if(A[i][j]==1)
        {
             cout<<j<<" ";
             s.push(j);
        }

    }
    cout<<endl;
}
queue<int>s2;
s2.push(0);
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        if(A[i][j]==1)
        {
           	while(!s2.empty())
             {
                if((s2.front())==j)
                 {
                   flag = 1;
                 }
                  cout<<"\n"<<s2.front()<<endl;
                  s2.pop();


             }
          if(visited[j]==0&&flag==0)
            {
               s2.push(j);
               visited[j] = 1;
            }
        }

    }
}






*/

/*

	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	cout<<"\nSize of queue s :"<<s.size();
	cout<<"\nFront element is : "<<s.front();
	cout<<"\nBack element is : "<<s.back()<<endl<<endl;
	queue<int>s1; // so that original queue s won't get affected
	s1 = s;
	cout<<"dequeing"<<endl;
	while(!s1.empty())
	{
		cout<<s1.front()<<" -- Size of queue s1 before dequeue "<<s1.size()<<endl<<endl;
		s1.pop();

	}
	cout<<"Size of queue s1 = "<<s1.size();
	*/

}

