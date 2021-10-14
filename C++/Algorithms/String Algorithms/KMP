#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define mod 998244353
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
#define F(i,a,n) for(int i=a;i<n;i++)



#define INF 100000000000


ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


using namespace std;

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

/*

    Knuth Morris Pratt (KMP) Algorithm
    Time Complexity : O(|S|+|P|) 
    Problem link : https://www.spoj.com/problems/NAJPF/
    

*/

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
    
        string text,pattern;
        cin>>text>>pattern;
        
        string s=pattern+'#'+text;
        int n=s.length();
        int lps[n+1]={};
        lps[0]=-1;
        int i=0,j=-1;
        while(i<n)
        {
            while(j!=-1 && s[i]!=s[j])
                j=lps[j];
            i++;
            j++;
            lps[i]=j;
        }
        int ct=0;
        int m=pattern.length();
        for(int i=m+1;i<=n;i++)
        {
            if(lps[i]==m)
             ct++;
        }
        
        cout<<ct<<'\n';
        
    }
    return 0;

}
