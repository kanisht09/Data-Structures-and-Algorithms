#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000

#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)



using namespace std;


ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

ll fermat_inv(ll y) {return binpow(y, mod - 2);}


// Euler Tree Technique

// -> representation of a tree in the form of an array

// flat tree array will be twice the size of number of nodes

vector<ll>adj[200005];
vector<ll>FT(400005);
vector<ll>S(200005);
vector<ll>T(200005);

ll timer=1;

void dfs(ll node,ll par)
{
    FT[timer]=node;
    S[node]=timer;
    timer++;
    for(auto u:adj[node])
    {
        if(u!=par)
        {
            dfs(u,node);
        }
    }
    FT[timer]=node;
    T[node]=timer;
    timer++;
}



int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        m=n-1;
        ll x,y;
        for(ll i=1;i<=n;i++)
        {
            adj[i].clear();
            FT[i]=0;
            S[i]=0;
            T[i]=0;
        }
        for(ll i=0;i<m;i++)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        timer=1;
        dfs(1,-1);
        for(ll i=1;i<=2*n;i++)
        {
            cout<<FT[i]<<" ";
        }
        cout<<"\n";
        for(ll i=1;i<=n;i++)
        {
            cout<<S[i]<<" ";
        }
        cout<<"\n";
        for(ll i=1;i<=n;i++)
        {
            cout<<T[i]<<" ";
        }
        cout<<"\n";

    }
    



    return 0;

}
