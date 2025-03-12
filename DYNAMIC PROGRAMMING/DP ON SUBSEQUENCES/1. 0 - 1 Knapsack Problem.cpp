#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    
    int solve(int n, int weight, vector<int>&val, vector<int>&wt,  vector<vector<int>> &dp){
        
        if(n == 0 || weight == 0) return 0;
        
        if(dp[n][weight] != -1) return dp[n][weight];
        
        if(wt[n-1] <= weight){
            
            int take = val[n-1] + solve(n-1, weight - wt[n-1] , val, wt, dp);
            int notTake = solve(n-1, weight, val, wt, dp);
            
            return dp[n][weight] =  max(take,notTake);
        }
        
        else if(wt[n-1] > weight){
            
            return dp[n][weight] = solve(n-1, weight, val, wt, dp);
        }
    }
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        
        // return solve(n,W,val,wt,dp);
        
        vector<vector<int>> dp(n+1, vector<int>(W+1,0));
        
        for(int i=1; i<n+1; i++){
            
            for(int j=1; j<W+1; j++){
                
                if(wt[i-1] <= j){
                    
                    dp[i][j] = max( val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
                }
                
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
        
        
    }
};
