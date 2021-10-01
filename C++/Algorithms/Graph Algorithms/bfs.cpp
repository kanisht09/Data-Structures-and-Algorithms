#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<pair<int,int>> q;
	bool vis[n+1];
	memset(vis,0,sizeof(vis));
	vis[1]=true;
	q.push({1,0});
	int dis[n+1];
	dis[1]=0;
	while(!q.empty()){
		int nd=(q.front()).first;
		int d=(q.front()).second;
		dis[nd]=d;
		q.pop();
		for(auto it:adj[nd]){
			if(!vis[it]){
				vis[it]=true;
				q.push({it,d+1});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" : "<<dis[i]<<endl;
	}
        return 0;
}