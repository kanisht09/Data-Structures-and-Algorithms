// Single source shortest path
#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back 
using namespace std;
 
 
vector<ll>adj[1005];
vector<ll>visited(1005,0);
vector<ll>dis(1005,0);
void dfs(ll node)
{
	visited[node]=1;
	for(auto i:adj[node])
	{
		if(!visited[i])
		{
			dis[i]=dis[node]+1;
			dfs(i);
		}
	}
}
 
int main()
{
	ll n;
	cin>>n;
	ll x,y;
	for(ll i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	//Calculates distance of each node from root node i.e 1
	for(ll i=2;i<=n;i++)
	{
		cout<<dis[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
