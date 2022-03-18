#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)

#define all(x) x.begin(), x.end()
#define F(i,a,n) for(int i=a;i<n;i++)
#define vll vector<ll>
#define vi vector<int>

#define INF 100000000000


ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


using namespace std;


// Binary lifting for LCA 
/* Problem Links : 
    
    https://www.spoj.com/problems/LCA/
    https://cses.fi/problemset/task/1135
 
*/

int par[1001][20];
int depth[1001];
vector<int>adj[1001];

void dfs(int src, int prev = 0, int lev = 0)
{
    depth[src] = lev;
    par[src][0] = prev;
    for (int i = 1; i < 20; i++)
    {
        par[src][i] = par[par[src][i - 1]][i - 1];
    }
    for (auto i : adj[src])
    {
        if (i != prev)
        {
            dfs(i, src, lev + 1);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    for (int i = 19; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1LL << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)return u;

    for (int i = 19; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];

}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);




    int tt;
    tt = 1;
    cin >> tt;
    // while (t--)
    for (ll w = 1; w <= tt; w++)
    {
        // Binary Lifting


        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            depth[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                par[i][j] = 0;
            }
        }
        int x;
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                adj[i].pb(x);
                adj[x].pb(i);
            }
        }
        dfs(1);
        cout << "Case " << w << ":\n";
        int q;
        cin >> q;
        int u, v;
        while (q--)
        {
            cin >> u >> v;
            cout << lca(u, v) << "\n";
        }

    }
    return 0;

}
