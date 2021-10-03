#include <bits/stdc++.h>
#define pb push_back
#define ll  long long
#define jaldi() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//   cout<<"Case #"<<t1-t<<": "<<ans<<"\n";     //KICKSTART
//  cout<<fixed<<setprecision(10)<<ans<<"\n";   // print ans upto 10 dp
// 2D Vector with known rows ---> vector<vector<int>> (n);   /// with n rows and n columns vector<vector<int>> v(n,vector(m)); 
using namespace std;
/*bool cmp(vector<int>:: iterator it1,vector<int>:: iterator it2)
{
    if(*it1>*it2)
    return true;
    else
    return false;
}*/
/*bool cmp(int a, int b)
{
    if(abs(a)>abs(b))
    return true;
    else
    return false;
}*/
/*ll int gcd(ll int a,ll int b)
{
    if(a==0)
    return b;
    else return gcd(b%a,a);
}*/
/*bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first<p2.first)
    return true;
    else if(p1.first==p2.first)
    {
        if(p1.second<p2.second)
        return true;
        else
        return false;
    }
    else
    return false;
}
*/
ll int mod=1000000007;
/*ll int powmd(ll int a,int p)
{
    ll int ans=1;
    ll int mp=a;
   
    while(p)
    {
        if(p&1) { ans*=mp; ans%=mod;}
        mp*=mp; p>>=1; mp%=mod; 
    }
 
    return ans;
}*/
/*int dp[100001];
string s;
int calc(int n)
{
    if(dp[n]!=-1) return dp[n];
    if(n==0) return dp[n]=1;
     if(n==1) 
    {
        if((s[n]=='u'&&s[n-1]=='u')||(s[n]=='n'&&s[n-1]=='n'))
        return dp[n]=2;
        else
        return dp[n]=calc(n-1);
    }
    if((s[n]=='u'&&s[n-1]=='u')||(s[n]=='n'&&s[n-1]=='n'))
    return dp[n]=(calc(n-1)%mod)+(calc(n-2)%mod);
    else
    return dp[n]=calc(n-1)%mod;
}*/
/*int dp[5001][5001];
string s1,s2;
int calc(int n1,int n2)
{
    if(n1==0&&n2==0) return dp[n1][n2]=0;
    if(n1==0) return dp[n1][n2]=n2;
    if(n2==0) return dp[n1][n2]=n1;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1-1]==s2[n2-1])
    return dp[n1][n2]=calc(n1-1,n2-1);
    int mn=min(calc(n1-1,n2-1),min(calc(n1-1,n2),calc(n1,n2-1)))+1;
    return dp[n1][n2]=mn;
}*/
 
int main() {
    jaldi();
 
   // freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
   
  // memset(dp,-1,sizeof(dp));
   int tcs=1,T;
   //cin>>T;  
   T=1;
   while((tcs++)<=T){
      int ht,wd;
      cin>>ht>>wd;
      int dp[ht+1][wd+1];
      for(int i=1;i<=ht;i++)
      {
          for(int j=1;j<=wd;j++)
          {
              if(i==j) dp[i][j]=0;
              else
              {     int res=INT_MAX;
                  for(int ct=1;ct<i;ct++)
                  res=min(res,1+dp[i-ct][j]+dp[ct][j]);
                  for(int ct=1;ct<j;ct++)
                  res=min(res,1+dp[i][j-ct]+dp[i][ct]);
                  dp[i][j]=res;
              }
          }
      }
      cout<<dp[ht][wd];
   }
    return 0;
}