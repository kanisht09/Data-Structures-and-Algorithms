#include<bits/stdc++.h>
#define F(i,a,b) for(ll i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;




const int N = 1000000;
const int M = 25;
vector<int>adj[N + 1];
int parent[N + 1][M + 1];
ll dp[N + 1][M + 1];
ll a[N + 1];
int dep[N + 1];

void dfs(int src, int par = 0, int lev = 0) {
    dep[src] = lev;
    dp[src][0] = a[src];
    parent[src][0] = par;
    for (int i = 1; i <= M; i++) {
        parent[src][i] = parent[parent[src][i - 1]][i - 1];
        dp[src][i] = __gcd(dp[src][i - 1], dp[parent[src][i - 1]][i - 1]);
    }
    for (auto i : adj[src]) {
        if (i == par)continue;
        dfs(i, src, lev + 1);
    }
}

ll pathGcd(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    ll ans = 0;
    for (int i = M; i >= 0; i--) {
        if ((dep[x] - dep[y]) & (1LL << i)) {
            ans = __gcd(ans, dp[x][i]);
            x = parent[x][i];
        }
    }
    if (x == y) {
        return __gcd(ans, a[x]);
    }
    for (int i = M; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            ans = __gcd(ans, dp[x][i]);
            x = parent[x][i];
            ans = __gcd(ans, dp[y][i]);
            y = parent[y][i];
        }
    }
    ans = __gcd(ans, a[x]);
    ans = __gcd(ans, a[y]);
    return __gcd(ans, a[parent[x][0]]);
}


int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // cout << "hello\n";
    int tc;
    // srand(time(NULL));
    tc = 1;

    cin >> tc;
    // createSieve();
    // cout << tc << '\n';
    // factorial(1000001);
    for (int _ = 1; _ <= tc; _++)
    {
        int n;
        cin >> n;

        // cout << n << '\n';
        int x, y, z;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            cin >> a[i];
            // cout << b[i - 1] << '\n';
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= M; j++) {
                parent[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }


        int q;
        cin >> q;
        dfs(1, 0, 0);
        while (q--)
        {
            cin >> x >> y;
            cout << pathGcd(x, y) << '\n';
        }


    }
    return 0;
}

/*


*/
