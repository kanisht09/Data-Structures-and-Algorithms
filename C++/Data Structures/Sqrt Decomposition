// problem link: https://www.spoj.com/problems/RMQSQ/

#include <bits/stdc++.h>
#define ll long long int
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
#define Ans(a,b) cout<<"Case #"<<a<<": "<<b<<"\n";
//const int mod = 1000000007;
const int mod = 998244353;
using namespace std;
 
const int bsize = 700;
ll a[100005];
ll f[705];
// Sqrt Decomposition
// query 0 based indexing
 
ll  getmin(ll l, ll r)
{
    ll lb = l / bsize;
    ll rb = r / bsize;
    ll mn = INT_MAX;
    if (rb == lb)
    {
        F(i, l, r + 1)
        {
            mn = min(mn, a[i]);
        }
    }
    else
    {
        F(i, l, (lb + 1)*bsize)
        {
            mn = min(mn, a[i]);
        }
        F(i, lb + 1, rb)
        {
            mn = min(mn, f[i]);
        }
        F(i, rb * bsize, r + 1)
        {
            mn = min(mn, a[i]);
        }
 
    }
    return mn;
}
 
 
int main()
{
 
 
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
    F(i, 0, n)
    {
        cin >> a[i];
    }
    ll maxi = INT_MAX;
    ll temp = 0;
    F(i, 0, n)
    {
        if (temp != (i / bsize))
        {
            temp = i / bsize;
            maxi = INT_MAX;
        }
        maxi = min(maxi, a[i]);
        f[i / bsize] = maxi;
    }
 
    ll q;
    cin >> q;
    ll x, y;
    while (q--)
    {
        cin >> x >> y;
        cout << getmin(x, y) << "\n";
    }
 
    return 0;
 
}
// For 10^5 Block size=700
 

