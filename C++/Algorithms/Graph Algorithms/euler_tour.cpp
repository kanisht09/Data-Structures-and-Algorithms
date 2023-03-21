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



*/

const int N = 100001;
const int mod = 1e9 + 7;


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



vector<int>adj[N];
vector<int>st(N);
vector<int>et(N);
vector<int>ft(2 * N);

int _time = 0;
void dfs(int src, int par = -1) {

	st[src] = ++_time;
	ft[_time] = src;
	for (auto i : adj[src]) {
		if (i != par) {
			dfs(i, src);
		}
	}
	et[src] = ++_time;
	ft[_time] = src;
}


int main() {

	int tc;
	tc = 1;
	// cin >> tc; // take test cases
	while (tc--) {

		int n, x, y;
		cin >> n;

		/*

			4
			1 2
			1 3
			3 4

		*/


		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);

		}

		_time = 0;
		dfs(1, -1);
		for (int i = 1; i <= n; i++) {
			cout << st[i] << ' ';
		}
		cout << '\n';
		for (int i = 1; i <= n; i++) {
			cout << et[i] << ' ';
		}
		cout << '\n';
		for (int i = 1; i <= 2 * n; i++) {
			cout << ft[i] << ' ';
		}
		cout << '\n';

		/*

			If we want to calculate the number of nodes in the subtree of node x

			we just need to know the starting time of node x and its ending time

			number of nodes in the subtree of node x = (et[x]-st[x]-1)/2

		*/

		int src = 3;
		cout << (et[src] - st[src] - 1) / 2 << '\n';




	}


	return 0;

}
