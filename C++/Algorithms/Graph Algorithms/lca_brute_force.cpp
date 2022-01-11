#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;

vector<ll>vis(100005,0);
vector<ll>adj[100005];
vector<ll>level(100005,0);
vector<ll>par(100005,0);
void dfs(ll node)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            par[i]=node;
            level[i]=level[node]+1;
            dfs(i);
        }
    }
}

ll LCA(ll x,ll y)
{
    if(level[x]<level[y])
    {
        swap(x,y);
    }
    ll d=level[x]-level[y];
    while(d>0)
    {
        x=par[x];
        d--;
    }
    if(x==y)return x;
    while(par[x]!=par[y])
    {
        x=par[x];
        y=par[y];
    }
    return par[x];
}

int main()
{
    // Lowest Common Ancestor in O(Tree Height) -> O(N)
    // N nodes
    
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        vis[i]=0;
        adj[i].clear();
        level[i]=0;
        par[i]=0;
    }
    ll x,y;
    for(ll i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    for(ll i=1;i<=n;i++)
    {
        cout<<level[i]<<" ";
    }
    cout<<"\n";
    cout<<LCA(2,7)<<"\n";
   
    return 0;
}
