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



const int N = 100001;

vector<int>adj[N];
vector<int>adjT[N];
vector<int>label(N);
vector<int>vis(N);

int n, m;
int mrk = 0;
void dfs(int node, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st);
        }
    }

    st.push(node);
}

void dfs3(int node) {
    vis[node] = 1;
    label[node] = mrk;
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs3(it);
        }
    }
}
void kosaraju() {


    stack<int> st;
    for (int i = 1; i <= n ; i++) {
        if (!vis[i]) {
            dfs(i, st);
        }
    }
    for (int i = 1; i <= n ; i++) {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            mrk++;
            dfs3(node);
        }
    }

}
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
    }
    kosaraju();
    cout << mrk << '\n';
    for (int i = 1; i <= n; i++) {
        cout << label[i] << ' ';
    }
    cout << '\n';


    return 0;
}
