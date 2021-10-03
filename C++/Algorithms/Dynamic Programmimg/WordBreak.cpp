#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto el : wordDict) st.insert(el);
        int n=s.length();
        int dp[n+1]; memset(dp,0,sizeof(dp)); 
        //dp[n+1]=1;
        for(int i=n;i>=1;i--)
        {   string tmp="";
            for(int j=i;j<=n;j++)
            {
                tmp+=s[j-1];
                if(st.find(tmp)!=st.end()&&((j<n&&dp[j+1])||j==n)) dp[i]=1;
            }
        }
        cout<<dp[1]<<" ";
        return dp[1];
    }
int main()
{	string s,s1;
	int n;
	cout<<"Enter the String s that is to be segmented and checked"<<"\n";
	cin>>s;
	vector<string> v;
	cout<<"Enter the number of words that are to be included in the Dictionary";
	cin>>n;
	for(int i=0;i<n;i++) { cin>>s1; v.pb(s1);}
	if(wordBreak(s,v)) cout<<"Entered string can be segmented into the words of the dictionary";
	else "Entered string cannot be segmented into the words of the dictionary";
	
return 0;
}