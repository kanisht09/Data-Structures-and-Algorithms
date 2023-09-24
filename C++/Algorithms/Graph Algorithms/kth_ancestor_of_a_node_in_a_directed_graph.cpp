#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define ld long double

using namespace std;

#define F(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

#define vi vector<int>
#define vll vector<ll>
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


// K-th parent of the i-th node in a directed graph
// O(log N) per query
// O(NlogN) precomputation

const int N = 200000;
const int M = 30;



int n, q;

int par[N + 1][M];


int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);




    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> par[i][0]; // j^0 parent of i-th node
    }

    for (int d = 1; d < 30; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            // pre-computation
            // j^d parent of i-th node
            par[i][d] = par[par[i][d - 1]][d - 1];
        }
    }

    int x, y;

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        int ans = x;

        // taking binary jumps
        for (int j = 0; j < 30; j++) {
            if (y & (1 << j))
            {
                ans = par[ans][j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
