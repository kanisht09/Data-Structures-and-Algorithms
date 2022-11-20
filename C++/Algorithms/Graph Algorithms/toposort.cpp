// practice problem :  https://www.spoj.com/problems/TOPOSORT/

#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define all(x)  x.begin(),x.end()


using namespace std;

template <typename T>
void trav(vector<T>v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<'\n';
}


// Graph Template


int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

vector<int>adj[1000001];
vector<int>vis(1000001);
vector<int>indeg(1000001);

void topodfs(int src,vector<int>&s){
    
    vis[src]=1;
    for(auto ch:adj[src]){
        if(!vis[ch]){
            topodfs(ch,s);
        }
    }
    s.pb(src);
}

vector<int>topobfs(int n){
    
    // queue<int>q;
    priority_queue<int,vector<int>,greater<int>>q; // for particular ordering
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        
        auto cur=q.top();
        q.pop();
        topo.pb(cur);
        for(auto it:adj[cur]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc_;
    tc_=1;
    // cin>>tc_;
    while(tc_--)
    {
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
            indeg[i]=0;
        }
        int x,y;
        for(int i=0;i<e;i++){
            cin>>x>>y;
            adj[x].pb(y);
            indeg[y]++;
            // adj[y].pb(x); // comment for directed
        }
        vector<int>s=topobfs(n);
        if(s.size()!=n){
            
            cout<<"Sandro fails.\n";
        }
        else{
           
            trav(s);
        }
    }
    
    
    return 0;
}
