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

// const ll mod = 998244353;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

using namespace std;


void trav(vector<ll>v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}


const int N = 200001;

vector<int>adj[N];
vector<int>dep(N);
vector<int>parent(N);
vector<int>sub(N);
int D;
ll ct = 0;
int op;
void dfs(int src, int par, int depth) {

    dep[src] = depth;
    if ( dep[src] == D / 2) {
        ct++;
    }

    parent[src] = par;
    sub[src] = 1;
    bool leaf = true;
    for (auto i : adj[src]) {

        if (i == par)
        {
            continue;
        }
        dfs(i, src, depth + 1);
        sub[src] += sub[i];
    }



}





int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tc;
    // srand(time(NULL));
    tc = 1;
    // cin >> tc;

    while (tc--)
    {
        int n, x, y;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);

        }
        if(n==1){
            cout<<1<<'\n';  // number of diameters
        }
        else{
        	dfs(1, 0, 0);
        int sx = 1;
        for (int i = 2; i <= n; i++) {
            if (dep[i] > dep[sx]) {
                sx = i;
            }
        }
        dfs(sx, 0, 0);
        for (int i = 1; i <= n; i++) {
            if (dep[i] > dep[sx]) {
                sx = i;
            }
        }
        D = dep[sx]; // Diameter of the tree
        if (D & 1) {
            // 2 centers

            if (D == 1) {
                cout << 1 << '\n';  // number of diameters
            }
            else {
                int tr = D / 2;
                int c1 = sx;
                while (tr--) {
                    c1 = parent[c1];
                }
                int c2 = parent[c1];
                ct = 0;
                dfs(c1, c2, 0);
                ll x1 = ct;
                ct = 0;
                dfs(c2, c1, 0);
                ll y1 = ct;
                ll res = x1 * y1;
                cout << res << '\n'; // number of diameters
            }



        }
        else {
            // 1 center
            op = 1;
            int tr = D / 2;
            int c = sx;
            while (tr--) {
                c = parent[c];
            }
            vector<ll>v;
            ll sum = 0;
            ll cum = 0;
            for (int x : adj[c]) {
                ct = 0;
                dfs(x, c, 1);
                v.pb(ct);
                sum += ct;
                cum += (ct * ct);
            }
          
            ll res = (sum * sum - cum) / 2;
            cout << res << '\n'; // number of diameters
           


        }    
        }
        
    }
    return 0;
}
