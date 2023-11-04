// problem link : https://atcoder.jp/contests/abc230/tasks/abc230_e
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
// #define INF 1e18
#define mod 998244353
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

bool primech(ll n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


bool prime[10000005];
void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (ll i = 2; i * i <= 10000001; i++)
    {
        if (prime[i] == 1)
        {
            for (ll j = i * i; j <= 10000001 ; j += i)
            {
                prime[j] = 0;
            }
        }
    }

}
ll binpowmod(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % m) * (a % m)) % m;
        }
        a = ((a % m) * (a % m)) % m;
        b >>= 1;
    }
    res %= m;
    return res;
}

void trav(vector<ll>v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tc;
    tc = 1;
    // cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = 1, j; i <= n; i = j + 1)
        {
            j = n / (n / i);

            ans += (n / i) * (j - i + 1);
        }
        cout << ans << '\n';

    }



    return 0;

}
