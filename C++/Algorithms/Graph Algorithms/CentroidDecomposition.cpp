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

const int N=1000001;
set<int>adj[N];
vector<int>sub(N);
vector<int>parent(N);
// findSubTreeSize() calculates subtree size of each node
int findSubTreeSize(int src,int par=0){
    sub[src]=1;
    for(auto i:adj[src]){
    
        if(i==par)
            continue;
    
        sub[src]+= findSubTreeSize(i,src);
    }
    return sub[src];
}
// findCentroid helper function to get centroid
int findCentroid(int src,int par,int n){
    
    for(auto i:adj[src]){
        if(i!=par && sub[i]>(n/2)){
            return findCentroid(i,src,n);
        }
    }
    return src;
}

void decompose(int src,int par=0){
    
    int subTreeSize=findSubTreeSize(src);
    int centroid=findCentroid(src,par,subTreeSize);
    parent[centroid]=par;
    for(auto ch:adj[centroid]){
        adj[ch].erase(centroid);
        decompose(ch,centroid);
    }
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // srand(time(NULL));
    int tc_;
    tc_=1;   
    // cin>>tc_;  // take test cases
    while(tc_--)
    {
        int n,x,y;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        decompose(1);
        for(int i=1;i<=n;i++){
            cout<<i<<" has parent : "<<parent[i]<<"\n";
        }
        
        
    }
 
    return 0;
}

/*
 input : 
 
 15
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15


*/
