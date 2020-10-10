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
 
vector<ll>R(100010, 0);
vector<ll>par(100010);
 
 
/* Includes both path compression and union by rank
 O(inverse of ackerman function) -> based on amortized analysis
 */
 
int Find(int x)
{
    if (par[x] < 0)
        return x;
    return par[x] = Find(par[x]);
}
void Union(int x, int y)
{
    if (R[x] > R[y])
    {
        par[x] += par[y];
        R[x] += R[y];
        par[y] = x;
    }
    else
    {
        par[y] += par[x];
        R[y] += R[x];
        par[x] = y;
    }
}
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    /*
    To find the no of connected components in a graph and length of each
    connected component using DSU
    */
 
    ll n, e;
    cin >> n >> e; // nodes // edges
 
    F(i, 1, n + 1)
    {
        par[i] = -1;
        R[i] = 1;
    }
 
    /* In the par array the -ve elements will be the root of a single connected
    component and its magnitude will be the length of the connected component
    */
 
    ll x, y;
    F(i, 0, e)
    {
        cin >> x >> y;
        x = Find(x);
        y = Find(y);
        if (x != y)
        {
            Union(x, y);
        }
    }
    vector<ll>length; // willl store length of each connected component
    F(i, 1, n + 1)
    {
        if (par[i] < 0)
        {
            length.pb(abs(par[i]) - 1);   // (-1)-> because it considers nodes we considering edges so -1
        }
    }
    cout << length.size() << "\n";
    for (auto i : length)
    {
        cout << i << " ";
    }
    cout << "\n";
}
