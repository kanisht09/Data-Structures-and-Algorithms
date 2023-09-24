#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
set<int> adj[N];
 
vector<int> B[N];
 
bool isBridge[N], visited[N];
 
int disc[N], low[N], par[N], label[N];
int cntr;
 
void dfs_bridge(int u, int prev){ // Bridge Finding
    visited[u] = 1;
    par[u] = prev;
    disc[u] = ++cntr;
    low[u] = disc[u];
 
    for(auto v : adj[u]){
        if(v == prev)   continue;
        if(visited[v] == false){ // un-explore node, so down in DFS tree
            dfs_bridge(v, u);
            if(low[v] > disc[u])    isBridge[v] = true;
        }
        low[u] = min(low[u], low[v]); // un-explored node OR back-edge
    }
}
 
void dfs_label(int u){ // Label each bridge component
    visited[u] = 1;
    label[u] = cntr;
    for(auto v : adj[u])
        if(!visited[v])
            dfs_label(v);
}
 
int main(){
    int n, m, u, v;
 
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
 
    vector<pair<int, int> > bridges;
 
    cntr = 0;
    dfs_bridge(1, 0);
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        if(isBridge[i]){
            bridges.push_back({i, par[i]});
            adj[i].erase(par[i]);
            adj[par[i]].erase(i);
        }
    }
 
    cntr = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cntr++;
            dfs_label(i);
        }
    }
 
    for(auto v : bridges){ // Make bridge tree
        int a = label[v.first], b = label[v.second];
        B[a].push_back(b);
        B[b].push_back(a);
    }
 
    return 0;
}
