#include <bits/stdc++.h>
#define pb push_back
#define ll long long
//   cout<<"Case #"<<t1-t<<": "<<ans<<"\n";
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
 
int main() {     
    
    // For getting input from input.txt file                                
   //freopen("input.txt", "r", stdin); 
    // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout); 
    //ll int mod=1e9+7;
    
    string s1,s2;
    cin>>s1>>s2;
   int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
  for(int i=0;i<=n;i++) dp[i][0]=i;
  for(int j=0;j<=m;j++) dp[0][j]=j;
  dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=m;j++)
      {
        //  dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
        //  dp[i][j]=min(+1,dp[i][j]);
          if(s1[i-1]==s2[j-1])
          dp[i][j]=dp[i-1][j-1];
          else
          dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j],dp[i][j-1])+1);
      }
  }
   cout<<dp[n][m]; 
}