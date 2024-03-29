#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define F(i,a,n) for(ll i=a;i<n;i++)
#define fil(ar, val) memset(ar, val, sizeof(ar))
using namespace std;

void printv(vector<ll>&a)
{
    for(auto &i:a)
        cout<<i<<" ";

    cout<<"\n";
}


int main()
{
   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // All pairs shortest path
    // Flyod warshall
    // https://cses.fi/problemset/task/1672/
    // O(n^3)
    
    ll n,m,x,y,z;
    cin>>n>>m;
    ll mat[n+1][n+1];
    for(ll i=1;i<n+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        {
            if(i!=j)
            mat[i][j]=1e18;
            else
            mat[i][j]=0;
        }
    }
    for(ll i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        mat[x][y]=min(z,mat[x][y]);
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
  
    return 0;
}
