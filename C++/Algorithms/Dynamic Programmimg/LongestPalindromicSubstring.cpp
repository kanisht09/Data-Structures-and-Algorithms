#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;


 string longestPalindrome(string s) {
        //int dp[s.length()+1][s.length()+1];
        //memset(dp,0,sizeof(dp));
        int best_start=0,best_end;
        int ans=1;
        int n=s.length();
        for(int i=1;i<=n-1;i++)
        {
            if(s[i-1]!=s[i]) continue;
          //  dp[i][i+1]=1;
            if(ans==1)
            {
                ans=2;
                best_start=i-1;
            }
            int l=i-1,h=i+2;
            while(l>=1&&h<=n)
            {
                if(s[l-1]!=s[h-1]) break;
               
                h++;l--;
            }
             if((h-l-1)>ans)
                {
                    ans=h-l-1;
                    best_start=l; 
                }
        }
        for(int i=2;i<=n-1;i++)
        {
             int l=i-1,h=i+1;
            while(l>=1&&h<=n)
            {
                if(s[l-1]!=s[h-1]) break;
               
                h++;l--;
            }
             if((h-l-1)>ans)
                {
                    ans=h-l-1;
                    best_start=l; 
                }
        }
        return s.substr(best_start,ans);
    }
int main()
{	string s;
	cout<<"Enter the String"<<"\n";
	cin>>s;
	cout<<longestPalindrome(s);
	
return 0;
}
