#include <bits/stdc++.h>
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nu 100
#define INF 100000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
 
#define tc int t;cin>>t;while(t--)
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
 
const int mod = 1000000007;
 
 
using namespace std;
 
 
vector<ll>adj[100010];
vector<ll>vis(100010, 0);
vector<ll>par(100010);



void dfs(ll node)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            par[i] = node;
            dfs(i);
        }
    }
}
 
int main()
{
 

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    // DFS traversal of a tree rooted at 1
 
    ll n, e;
    cin >> n >> e; // nodes // edges
    for (ll i = 1; i <= n; i++)
    {
        vis[i] = 0;
        adj[i].clear();
    }
    ll x, y;
    for (ll i = 1; i <= e; i++)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    for (ll i = 1; i <= n; i++)
    {
        cout << i << "-->";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
 
}
