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
#define INF 1e14
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
#define Ans(a,b) cout<<"Case #"<<a<<": "<<b<<"\n";
#define inter(i,j) cout<<"? "<<i<<" "<<j<<endl;fflush(stdin);
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define debuga(x)  cout<<"# "<<x<<"\n";
#define debugb(x,y) cout<<"# "<<x<<"  "<<y<<"\n"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
//const int mod = 998244353;
// #define Maxi 1e-14


// O(Nlog(log(sqrt(N))))
ll spf[1000005];
void createSieve()
{
    for (ll i = 1; i <= 1000001; i++)
    {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= 1000001; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= 1000001; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}



int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);




    createSieve();
    ll t;
    t = 1;
    cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {

        // O(log(N))
        ll n;
        cin >> n;
        while (n != 1)
        {
            cout << spf[n] << " ";
            n /= spf[n];
        }
        cout << "\n";




    }
    return 0;


}

// For 10^5 Block size=700


// ctrl+alt+b
