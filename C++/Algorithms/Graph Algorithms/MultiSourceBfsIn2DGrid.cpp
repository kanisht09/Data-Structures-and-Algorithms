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
 
 
 
// problem link : https://cses.fi/problemset/task/1194/
 
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string dir = "DURL";
 
int n, m;
char a[1001][1001];
pair<int, int> parent[1001][1001];
 
bool monster(int x, int y) {
	return a[x][y] == 'M';
}
 
bool man(int x, int y) {
	return a[x][y] == 'A';
}
 
bool isvalid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')
		return false;
	return true;
}
 
void bfs(vector<pair<int, int>>&v, vector<vector<ll>>&dis, int type) {
 
	queue<pair<int, int>>q;
	for (auto src : v) {
 
		dis[src.ff][src.ss] = 0;
		q.push({src.ff, src.ss});
 
	}
 
	while (!q.empty()) {
 
		auto src = q.front();
		q.pop();
		int x = src.ff;
		int y = src.ss;
		int curd = dis[x][y];
		for (int i = 0; i < 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if (!isvalid(sx, sy)) {
				continue;
			}
			if (type == 1) {
 
				if (monster(sx, sy)) {
					continue;
				}
			}
			else
			{
				if (man(sx, sy)) {
					continue;
				}
			}
 
			if (dis[sx][sy] > 1 + curd)
			{
				dis[sx][sy] = 1 + curd;
				q.push({sx, sy});
				if (type == 1) {
					parent[sx][sy] = {x, y};
 
				}
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
		vector<pair<int, int>>pm, pa;
		vector<vector<ll>>disa(n, vector<ll>(m));
		vector<vector<ll>>dism(n, vector<ll>(m));
 
 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'M') {
					pm.pb({i, j});
				}
				else if (a[i][j] == 'A') {
					pa.pb({i, j});
				}
				disa[i][j] = 1e9;
				dism[i][j] = 1e9;
			}
		}
		bfs(pa, disa, 1);
		bfs(pm, dism, 0);
 
		int desx = -1;
		int desy = -1;
		for (int i = 0; i < n; i++) {
			if ( disa[i][0] < dism[i][0]) {
				desx = i;
				desy = 0;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if ( disa[i][m - 1] < dism[i][m - 1]) {
				desx = i;
				desy = m - 1;
				break;
			}
		}
		for (int j = 0; j < m; j++) {
			if ( disa[0][j] < dism[0][j]) {
				desx = 0;
				desy = j;
				break;
			}
		}
		for (int j = 0; j < m; j++) {
			if ( disa[n - 1][j] < dism[n - 1][j]) {
				desx = n - 1;
				desy = j;
				break;
			}
		}
		if (desx == -1 || desy == -1) {
			cout << "NO\n";
		}
		else {
 
			cout << "YES\n";
			// cout << desx << " " << desy << '\n';
			cout << disa[desx][desy] << '\n';
			pair<int, int>des = {desx, desy};
			pair<int, int>src = {pa[0].ff, pa[0].ss};
			vector<pair<int, int>>path;
			while (des != src) {
				path.pb(des);
				des = parent[des.ff][des.ss];
			}
			path.pb(src);
			reverse(all(path));
			// for (auto i : path) {
			// 	cout << i.ff << " " << i.ss << '\n';
			// }
			map<pair<int, int>, int>cachedir;
			for (int i = 0; i < 4; i++) {
				cachedir[ {dx[i], dy[i]}] = i;
			}
			string res = "";
			for (int i = 1; i < (int)path.size(); i++) {
				int x = path[i].ff - path[i - 1].ff;
				int y = path[i].ss - path[i - 1].ss;
				res += dir[cachedir[ {x, y}]];
			}
			cout << res << '\n';
 
		}
 
 
 
	}
 
 
	return 0;
 
}
