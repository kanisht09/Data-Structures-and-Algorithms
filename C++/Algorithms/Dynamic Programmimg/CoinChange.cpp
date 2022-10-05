/**
  * Question: You are given an array of coins of different denominations and a total amount of money.
  *           You need to return fewest coins needed to make up that amount.
  *           One coin denomination can be used multiple times.
  *           If the answer is not possible return -1.
  * Category: Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n+1][amount+1];
    
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=amount;++j)
        {
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = 1e5;
            else if(coins[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
        }
    }
    return dp[n][amount]>1e4 ? -1:dp[n][amount];
}

int main () {
    int amount = 0, noOfCoins = 0;
    cin >> amount >> noOfCoins;
    vector<int> coins(noOfCoins);
    for(int i=0; i<noOfCoins; i++) {
        cin >> coins[i];
    }
    cout << "No of ways: " << coinChange(coins, amount) << endl;
}