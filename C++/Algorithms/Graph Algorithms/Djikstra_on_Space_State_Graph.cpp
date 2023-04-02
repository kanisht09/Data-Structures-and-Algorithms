#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
// #define INF 1e18
#define mod 998244353
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

#define INF 100000000000


ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


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


bool prime[10000005];
void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (ll i = 2; i * i <= 10000001; i++)
    {
        if (prime[i] == 1)
        {
            for (ll j = i * i; j <= 10000001 ; j += i)
            {
                prime[j] = 0;
            }
        }
    }

}
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

/*

Problem Statement :


You want to visit the country of wonderland. There are N cities in the country. Not all cities are connected by roads. You know which cities are connected. 

You landed in city A, and you want to visit city B. You already booked your car, but it doesn’t have any petrol. The capacity of the tank of the car is C. You know the Per Liter cost of petrol in each city, and you also have the map of the country, i.e., you know the length of road between two cities. To travel one unit of distance, you need one liter of petrol.

Find the minimum cost to travel from city A to city B.


The first line of input contains N - the number of cities in the country of wonderland.
The second line contains M - the number of roads in the country.
Next M lines contain three integers u, v, d - there is a road between city u and v of length d.
The next lines contain N space-separated integers P[1], P[2], …., P[N] - P[i] is the per liter cost of petrol in the city i.
The last line of input contains A, B, and C - the starting city, the destination city, and the capacity of the tank of car you booked.
It’s guaranteed that it’s always possible to reach city B from A.

Output Format

Print the minimum cost to reach city B on a new line.


Constraints

1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ C ≤ 100
1 ≤ u, v ≤ N
1 ≤ d ≤ C
1 ≤ A, B ≤ N
1 ≤ P[i] ≤ 100
 
 
Input 1:
 
5
5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 6
1 10 10 10 1
1 5 8

Output : 4

*/



const int N = 10001;


vector<pair<ll, ll>>adj[N];
ll dis[N][101];
ll p[N];

using piii = pair<ll, pair<ll, ll>>;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tc;
    // srand(time(NULL));
    tc = 1;
    // cin >> tc;
    while (tc--)
    {
        ll n, m, x, y;
        cin >> n >> m;


        ll wt;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> wt;
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        }
        F(i, 1, n + 1) {
            cin >> p[i];
        }

        ll src, en, c;
        cin >> src >> en >> c;
        // cout << src << " " << en << " " << c << '\n';
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= c; j++) {

                dis[i][j] = 1e18;

            }
        }

        priority_queue<piii, vector<piii>, greater<piii>>pq;
        dis[src][0] = 0;
        pq.push({dis[src][0], {src, 0}});
        while (!pq.empty()) {
            int cur = pq.top().ss.ff;
            int fuel = pq.top().ss.ss;
            ll wt = pq.top().ff;
            // cout << cur << " " << fuel << " " << wt << '\n';
            pq.pop();
            if (dis[cur][fuel] != wt) {
                continue;
            }
            ll curwt = 0;

            if (fuel < c) {
                curwt = p[cur];
                if (dis[cur][fuel + 1] > curwt + dis[cur][fuel]) {
                    dis[cur][fuel + 1] = curwt + dis[cur][fuel];
                    pq.push({dis[cur][fuel + 1], {cur, fuel + 1}});
                }
            }

            for (auto node : adj[cur]) {
                ll child = node.ff;

                if (fuel >= node.ss) {
                    curwt = 0;
                    if (dis[child][fuel - node.ss] > curwt + dis[cur][fuel]) {
                        dis[child][fuel - node.ss] = curwt + dis[cur][fuel];
                        pq.push({dis[child][fuel - node.ss], {child, fuel - node.ss}});
                    }
                }

            }

        }
        ll mn = dis[en][0];
        for (int i = 1; i <= c; i++)
        {
            mn = min(dis[en][i], mn) ;
        }
        cout << mn << '\n';

    }

    return 0;

}
