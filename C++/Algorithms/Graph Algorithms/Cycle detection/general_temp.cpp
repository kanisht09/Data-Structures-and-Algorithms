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


vector<int>adj[N];
vector<int>col(N);
vector<int>parent(N);
vector<int>any_cycle;
vector<int>prefOrder;
vector<int>partOfCycle(N);
bool is_cycle = false;

void dfs(int src, int par) {

	parent[src] = par;
	col[src] = 2;
	for (auto child : adj[src]) {


		/* uncomment below lines for undirected graph */

		// if (child == par) {
		// 	continue;
		// }

		if (col[child] == 1)
		{
			// src to child is forward edge
			dfs(child, src);
		}
		else if (col[child] == 2) {

			// src to child is backward edge

			partOfCycle[src]++;
			partOfCycle[parent[child]]--;

			if (!is_cycle) {

				int temp = src;
				any_cycle.pb(child);
				while (temp != child) {
					any_cycle.pb(temp);
					temp = parent[temp];
				}
				any_cycle.pb(temp);
				reverse(all(any_cycle));


			}

			is_cycle = true;


		}
		else {

			// src to child is cross edge
			// unimportant
		}
	}
	col[src] = 3;
	prefOrder.push_back(src);
}


int main() {

	int tc;
	tc = 1;
	// factorial();
	// cin >> tc; // take test cases
	while (tc--) {

		int n, e, x, y;
		cin >> n >> e;
		prefOrder.clear();
		for (int i = 1; i <= n; i++) {
			col[i] = 1;
			partOfCycle[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < e; i++) {
			cin >> x >> y;
			adj[x].pb(y);
			// adj[y].pb(x); // uncomment for undirected graph
		}
		is_cycle = false;

		for (int i = 1; i <= n; i++) {
			if (col[i] == 1) {
				dfs(i, 0);

			}
		}

		if (is_cycle) {
			cout << any_cycle.size() << "\n";
			for (auto i : any_cycle) {
				cout << i << ' ';
			}
			cout << '\n';

		}
		else {
			cout << "No Cycle present.\n";
		}


		for (auto i : prefOrder) {
			partOfCycle[parent[i]] += partOfCycle[i];

		}
		int ct = 0; // stores nodes which are part of cycle
		for (auto i : prefOrder) {
			if (partOfCycle[i] > 0) {
				ct++;
			}
		}
		cout << ct << '\n';

	}


	return 0;

}
