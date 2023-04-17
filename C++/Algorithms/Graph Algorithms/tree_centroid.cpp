#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

// problem link : https://cses.fi/problemset/task/2079


using namespace std;

int n;
vector<int>adj[200001];
vector<int>sub(200001);
void dfs(int node,int par)
{
    sub[node]=1;
    for(auto i:adj[node])
    {
        if(i!=par)
        {
            dfs(i,node);
            sub[node]+=sub[i];
        }
    }
}
int find_centroid(int node,int par)
{
    for(auto i:adj[node])
    {
        if(i!=par && sub[i]>n/2)return find_centroid(i,node);
    }
    return node;
}


int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m;
    cin>>n;
    m=n-1;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    cout<<find_centroid(1,0)<<"\n";
    

    return 0;

}
