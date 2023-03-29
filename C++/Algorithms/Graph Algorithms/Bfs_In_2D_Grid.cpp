#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define F(i,a,n) for(ll i=a;i<n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

using namespace std;

/*

https://codeforces.com/problemset/problem/1486/B -> Manhatten distance

*/

const int N = 1000001;
const ll mod = 1e9 + 7;


ll binpow(ll a, ll b)
{
	a %= mod;
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = ((res % mod) * (a % mod)) % mod;
		}
		a = ((a % mod) * (a % mod)) % mod;
		b >>= 1;
	}
	return res;
}

ll fermat_inv(ll y) {return binpow(y, mod - 2);}

ll fact[N], finv[N];

void factorial() {

	fact[0] = 1;
	finv[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = i * fact[i - 1] % mod;
		finv[i] = fermat_inv(fact[i]);
	}
}

ll ncr(ll n, ll r) {


	if (r > n)
		return 0;
	if (r == 0) {
		return 1;
	}
	ll ans = (finv[n - r] * finv[r]) % mod;
	ans = (ans * fact[n]) % mod;
	return ans;
}



// Shortest distance from src node to destination node and number of shortest paths from src to des.


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char a[1001][1001];
pair<ll, ll> dis[1001][1001];

bool isvalid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m )
		return false;
	if ( a[x][y] == '#')
		return false;
	return true;
}

void bfs(int srcx, int srcy) {

	queue<pair<int, int>>q;
	dis[srcx][srcy] = {0, 1};
	q.push({srcx, srcy});

	while (!q.empty()) {

		auto src = q.front();
		q.pop();
		int x = src.ff;
		int y = src.ss;
		int curd = dis[x][y].ff;
		for (int i = 0; i < 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if (!isvalid(sx, sy)) {
				continue;
			}

			if (dis[sx][sy].ff > 1 + curd) {
				dis[sx][sy].ff = 1 + curd;
				dis[sx][sy].ss = dis[x][y].ss;
				q.push({sx, sy});

			}
			else if (dis[sx][sy].ff == 1 + curd) {
				dis[sx][sy].ss += dis[x][y].ss;
			}

		}
	}
}



int main() {

	int tc;
	tc = 1;
	// factorial();
	// cin >> tc; // take test cases
	while (tc--) {

		cin >> n >> m;
		int sx = 0;
		int sy = 0;
		int ex, ey;
		ex = ey = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				else if (a[i][j] == 'E') {
					ex = i;
					ey = j;
				}
				dis[i][j] = {1e9, 0};
			}
		}
		bfs(sx, sy);
		// cout << sx << " " << sy << '\n';
		cout << dis[ex][ey].ff << " " << dis[ex][ey].ss << '\n';

	}


	return 0;

}
