#include<bits/stdc++.h>
#define ll long long 
#define INF 1e9
using namespace std;
vector<ll>st(400005,0);
vector<ll>lt(100005,0);
vector<ll>a(100005,0);

void buildseg(ll si,ll ss,ll se)
{
    if(ss==se)
    {
        st[si]=a[ss];
        return;
    }
    ll mid=(ss+se)/2;
    buildseg(2*si,ss,mid);
    buildseg(2*si+1,mid+1,se);
    st[si]=st[2*si]+st[2*si+1];
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
    if(qs>se || ss>qe)
    return 0;
    if(ss>=qs && se<=qe)
    {
        return st[si];
    }
    ll mid=(ss+se)<<1;
    ll l=query(2*si,ss,mid,qs,qe);
    ll r=query(2*si+1,mid+1,se,qs,qe);
    return r+l;
}
void update(ll si,ll ss,ll se,ll qi,ll nv)
{
    if(ss==se)
    {
        a[ss]=nv;
        st[si]=a[ss];
        return;
    }
    ll mid=(ss+se)/2;
    if(qi<=mid)
        update(2*si,ss,mid,qi,nv);
    else
        update(2*si+1,mid+1,se,qi,nv);
        
    st[si]=(st[2*si]+st[2*si+1]);
}
ll rquery(ll si,ll ss,ll se,ll qs,ll qe)
{
    if(!lt[si])
    {
        ll cx=lt[si];
        lt[si]=0;
        st[si]+=(se-ss+1)*cx;
        if(ss!=se)
        {
            lt[2*si]+=cx;
            lt[2*si+1]+=cx;
        }
    }
    if(ss>qe || qs>se)
    {
        return 0;
    }
    if(ss>=qs && qe>=se)
    {
        return st[si];
    }
    ll mid=(ss+se)/2;
    ll l=rquery(2*si,ss,mid,qs,qe);
    ll r=rquery(2*si+1,mid+1,se,qs,qe);
    return l+r;
}
void rupdate(ll si,ll ss,ll se,ll qs,ll qe,ll nv)
{
    if(!lt[si])
    {
        ll cx=lt[si];
        lt[si]=0;
        st[si]+=(se-ss+1)*cx;
        if(ss!=se)
        {
            lt[2*si]+=cx;
            lt[2*si+1]+=cx;
        }
    }
    if(ss>qe || qs>se)return;
    if(ss>=qs && qe>=se)
    {
        st[si]+=(se-ss+1)*nv;
        if(ss!=se)
        {
            lt[2*si]+=nv;
            lt[2*si+1]+=nv;
        }
        return;
    }
    ll mid=(ss+se)/2;
    rupdate(2*si,ss,mid,qs,qe,nv);
    rupdate(2*si+1,mid+1,se,qs,qe,nv);
    st[si]=st[2*si]+st[2*si+1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    buildseg(1,1,n);
    ll x,l,r,p;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>l>>r>>p;
            l++;
            rupdate(1,1,n,l,r,p);
        }
        else
        {
            cin>>l>>r;
            l++;
            cout<<rquery(1,1,n,l,r)<<"\n";
        }
    }
    
} 
