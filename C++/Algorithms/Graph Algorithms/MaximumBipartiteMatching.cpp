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
// #define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)


#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define F(i,a,n) for(int i=a;i<n;i++)
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>



ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}

// const ll mod = 998244353;
const ll mod = 1e8 + 7;
// const ll mod = 1e8;

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

template <typename T>
void trav(vector<T>v)
{
	for (auto i : v)
	{
		cout << i << ' ';
	}
	cout << '\n';
}


const int N = 501;


vector<int>adj[N];
vector<int>vis(N);
vector<int>mt(N);


bool dfs(int x) {

	vis[x]=1;
	for(auto j:adj[x]) {

		if(mt[j]==-1 || !vis[mt[j]] && dfs(mt[j])) {
			mt[j]=x;
			return true;
		}
	}

	return false;
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int tc;
	// srand(time(NULL));
	tc = 1;
	// cin >> tc;


	for (int w = 1; w <= tc; w++)
	{
		int n,m,q;
		cin>>n>>m>>q;

		for(int i=0; i<n; i++) {
			adj[i].clear();
		}

		int x,y;
		for(int i=0; i<q; i++) {
			cin>>x>>y;
			x--,y--;
			// cout<<x<<" "<<y<<'\n';
			adj[x].pb(y);
		}

	
		int ans=0;
		for(int i=0; i<m; i++) {
			mt[i]=-1;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				vis[j]=0;
			}
			ans+=dfs(i);
		}
		cout<<ans<<'\n';

		for(int i=0; i<m; i++) {

			if(~mt[i])  // to check if mt[i] == -1 , ~x is -(x+1)
				cout<<mt[i]+1<<" "<<i+1<<'\n';
		}

	}
	return 0;
}

