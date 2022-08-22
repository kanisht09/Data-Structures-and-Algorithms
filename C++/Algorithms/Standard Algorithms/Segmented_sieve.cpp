
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


#define pll pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()

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
const int N = 1e6 + 5;
vector<bool>prime(N + 1, 1);
void sieve()
{
    prime[1] = 0;
    for (ll i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
vector<ll>generatePrimes(ll n)
{

    vector<ll>ds;
    if (n >= 2)
        ds.pb(2);
    for (ll i = 3; i <= n; i += 2)
    {
        if (prime[i])ds.pb(i);
    }
    return ds;
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    // Segmented Sieve  : primes in range [l,r] O(nlog(log(sqrt(n)))) + O(Q.sqrt(n)) , n=max(r);
    // Note : in [l,r] ; l should be greater than 1.

    int t;
    sieve();
    t = 1;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        l = max(l, 2LL);
        vector<ll>primes = generatePrimes(sqrt(r));
        vector<bool>seg(r - l + 1, 1);
        for (auto i : primes)
        {
            ll val = (l / i) * i;
            if (val < l)
                val += i;
            val = max(val, i * i);
            for (ll j = val; j <= r; j += i)
            {

                seg[j - l] = 0;
            }
        }
        ll ct = 0;
        for (ll i = l; i <= r; i++)
        {
            if (seg[i - l])
            {
                cout << i << " ";
                ct++;
            }
        }
        cout << "\n";
        cout << ct << "\n";
    }

    return 0;

}
