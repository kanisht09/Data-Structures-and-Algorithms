// Problem Link : https://cses.fi/problemset/task/1628/
// Complexity -> O(2^(n/2)) from O(2^(n)) 

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
using namespace std;
 
const ll mod = 1e9 + 7;
 
ll binpowmod(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    res %= m;
    return res;
}
ll s;
 
vector<ll>generate_subsetsums(vector<ll>&a)
{
    int n = a.size();
    vector<ll>sums;
    for (int i = 0; i < (1LL << n); i++)
    {
 
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1LL << j))
            {
                sum += a[j];
            }
        }
        if (sum <= s)
            sums.pb(sum);
    }
    return sums;
 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> s;
        vector<ll>b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (i & 1)
                b.pb(x);
            else
                c.pb(x);
        }
 
        b = generate_subsetsums(b);
        c = generate_subsetsums(c);
 
        map<ll, ll>mb, mc;
 
        for (auto u : b)
            mb[u]++;
 
 
        for (auto u : c)
            mc[u]++;
 
        if (b.size() > c.size())
            swap(b, c);
        ll ans = 0;
        for (auto i : mb)
        {
            ans += i.ss * (mc[s - i.ff]);
        }
        cout << ans << "\n";
 
 
 
    }
    return 0;
   }
