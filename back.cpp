#include<bits/stdc++.h>
using namespace std;


        
class Solution {
public:

    int cal(int n, int k , vector<int>prices,int dp[][]){

        int dp[n+1][k+1];
        for(int i=0;i<=k;i++)
            dp[0][i] = 0;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j] = dp[i-1][j];
                for(int f = 1 ; f < i ; f++){
                    dp[i][j] = max(dp[i][j],dp[f-1][j-1]+prices[i]-prices[f]);
                }
            }
        }

        return dp[n][k];

    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n][k];
        memset(dp,-1,sizeof(dp));
        return cal(n,k,prices,dp);
    }
};
        
        
      
