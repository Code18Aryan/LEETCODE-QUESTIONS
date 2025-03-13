
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    int solve(int n, int sum, vector<int>&coins,vector<vector<int>>&dp){
        
        if(n == 0) return 0;
        if(sum == 0 && n > 0) return 1;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(coins[n-1] <= sum){
            
            int take = solve(n, sum - coins[n-1], coins,dp);
            int notTake = solve(n-1,sum, coins,dp);
            
           return dp[n][sum] = take + notTake;
        }
        
        else return dp[n][sum] = solve(n-1,sum, coins,dp);
    }
  
    int count(vector<int>& coins, int sum) {
       
        int n = coins.size();
        
        // vector<vector<int>> dp (n+1, vector<int>(sum+1 , -1));
        
        // return solve(n,sum,coins,dp);
        
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));
        
        for(int i=1; i<n+1; i++){
            
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++){
            
            for(int j=1; j<sum+1; j++){
                
                if(coins[i-1] <= j){
                    
                    int take = dp[i][j - coins[i-1]];
                    int notTake = dp[i-1][j];
                    
                    dp[i][j] = take + notTake;
                }
                
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};


// } Driver Code Ends