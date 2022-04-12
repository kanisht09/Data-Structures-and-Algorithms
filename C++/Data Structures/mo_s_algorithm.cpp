#include <bits/stdc++.h>

#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define nui 100
#define pi 3.1415926535897932384626
#define nu 2
#define INF 100000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
#define Ans(a,b) cout<<"Case #"<<a<<": "<<b<<"\n";
//const int mod = 1000000007;
const int mod = 998244353;
using namespace std;

// Problem Link : https://www.spoj.com/problems/DQUERY/

const int blk=555;
struct query
{
    int l,r,i;
};

int fre[1000001];
int ct=0;
query Q[200001];
int a[30001];
int ans[200001];

bool cmp(query a,query b)
{
    if(a.l/blk !=b.l/blk)
    {
        return a.l/blk<b.l/blk;
    }
    return a.r<b.r;
}
void add(int pos)
{
    fre[a[pos]]++;
    if(fre[a[pos]]==1)
    {
        ct++;
    }
}
void remov(int pos)
{
    fre[a[pos]]--;
    if(fre[a[pos]]==0)
    {
        ct--;
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    F(i,0,n)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
        Q[i].l--,Q[i].r--;
    }
    sort(Q,Q+q,cmp);
    int ml=0;
    int mr=-1;
    for(int i=0;i<q;i++)
    {
        int L=Q[i].l;
        int R=Q[i].r;
        while(ml>L)
        {
            ml--;
            add(ml);
        }
        while(mr<R)
        {
            mr++;
            add(mr);
        }
        while(ml<L)
        {
            remov(ml);
            ml++;
        }
        while(mr>R)
        {
            remov(mr);
            mr--;
        }
        ans[Q[i].i]=ct;
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<"\n";
    }
          
    return 0;

}

// For 10^5 Block size=700
 
