#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode
{
    int vertexNo;
    struct ListNode *next;
};
struct Graph
{
    int v;
    int e;
    struct ListNode *Adj;
};
struct Graph*AdjListOfGraph()
{
    int i,x,y;
    struct ListNode *temp,*t;
    struct Graph *G;
    G = (struct Graph*)malloc(sizeof(struct Graph));
    cout<<"Enter number of vertices and edges : ";
    cin>>G->v>>G->e;
    G->Adj = (struct ListNode*)malloc(G->v * sizeof(struct ListNode));
    for(i=0;i<G->v;i++)
    { G->Adj+i->vertexNo = i;
      G->Adj+i->next = G->Adj+i
    }
    for(i=0;i<G->e;i++)
    {
        cout<<"Enter source and destination node ";
        cin>>x>>y;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->vertexNo = y;
        temp->next = G->Adj+x;
        t = G->Adj+x;
       while(t->next!=G->Adj+x)
            t= t->next;
       t->next =temp;
    }
 return (G);
}

int main()
{
    cout<<"hello";
}


