
/* Disjoint Set Union */

#include<bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

/* Considering both path compression and union by rank heuristic */

vector<ll>par(100005,0); // parent array
vector<ll>R(100005,0); // Rank array

int find(int x)    // Finds parent of a particular node
{
    if(par[x]<0)
        return x;
    else return par[x]=find(par[x]);
}
void Union(int x,int y) // merges two nodes of two different sets into a single set (ensuring that the tree formed is shallow)
{
    if(R[x]>R[y])
    {
        par[x]+=par[y];
        R[x]+=R[y];
        par[y]=x;
    }
    else
    {
        par[y]+=par[x];
        R[y]+=R[x];
        par[x]=y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;   // no. of nodes
    
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        R[i]=1;
    }
    /*After perfroming  find and Union operations, the -ve values in the par array are the parent of nodes present in the graph and its magnitude is the total no. of nodes connected to it or its children count including itself
    */
    int q; // queries
    cin>>q;
    int x,y;
    while(q--)
    {
        cin>>x>>y;
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            Union(x,y);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<par[i]<<" ";
    }
    
    return 0;
}

/* suppose the input is of this form 

8 5  // no of nodes ... no of queries n=8 q=5;
q lines follow :
1 2
1 4
3 5
7 8
1 6

The O/P obtained is :

2 -4 5 2 -2 2 8 -2

considering 1- based array index

1  2 3 4  5 6 7  8
2 -4 5 2 -2 2 8 -2

2 is the parent node having 4 nodes including itself
5 is the parent node having 2 nodes including itself
8 is the parent node having 2 nodes including itself

So we can say there are three connected-components in this graph
i.e; count of -ve entities in the par array

The complexity of DSU with both : path by compression and union by rank 
is O(q*α(n)) where α(n) is the inverse of Ackermann function .

Here is a sample problem link both easy and hard version can be solved by DSU 

https://codeforces.com/problemset/problem/1249/B1





*/


