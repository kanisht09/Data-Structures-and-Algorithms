#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
#define pll pair<ll,ll>



ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

const ll mod = 998244353;
// const ll mod = 1e9 + 7;
const ll INF = 1e18;

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


// bool prime[10000005];
// void sieve()
// {
//     memset(prime, 1, sizeof(prime));
//     prime[1] = 0;
//     for (ll i = 2; i * i <= 10000001; i++)
//     {
//         if (prime[i] == 1)
//         {
//             for (ll j = i * i; j <= 10000001 ; j += i)
//             {
//                 prime[j] = 0;
//             }
//         }
//     }

// }
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


const int N = 100001;

vector<int>adj[N];
int inTime[N], loTime[N];
int timer = 0;
void dfs(int src, int par) {

    // graph is 1-based indexing and par is passed as 0 initially

    timer++;
    inTime[src] = loTime[src] = timer;
    bool isArti = false;
    int child = 0;
    for (auto ch : adj[src]) {
        if (ch == par) {
            continue;
        }
        if (!inTime[ch]) { // src to ch is a forward edge
            child++;
            dfs(ch, src);
            loTime[src] = min(loTime[src], loTime[ch]);
            if (loTime[ch] >= inTime[src]) {
                isArti = true;
                // ch will form a new component
            }
            if (loTime[ch] > inTime[src]) {

                cout << src << " to " << ch << " is a bridge edge.\n";
                // src to ch is a bridge
            }
        }
        else {

            // back-edge

            loTime[src] = min(loTime[src], inTime[ch]);

        }
    }

    if ((par == 0 && child > 1) || (isArti && par != 0)) {
        // src is an articulation point
        cout << src << " is an articulation point.\n";
    }
}

/*

input : 

8 9
1 2
2 3
3 1
3 4
4 5
4 6
6 7
7 8
8 6

*/


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tc;
    // srand(time(NULL));
    tc = 1;
    // cin >> tc;

    while (tc--)
    {

        int n, m, x, y;
        cin >> n >> m;

        // reset
        timer = 0;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            inTime[i] = 0;
            loTime[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1, 0);

    }
    return 0;
}
