LINK - https://leetcode.com/problems/coin-change/description/


class Solution {
public:

    int findMin(int n, int amount, vector<int>&coins, vector<vector<int>> &dp){

        if(n == 0) return 1e9;
        if(amount == 0 && n > 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];

        if(coins[n-1] <= amount){

            int pick = 1 + findMin(n, amount - coins[n-1], coins,dp);
            int notPick = findMin(n-1,amount,coins,dp);

            return dp[n][amount] = min(pick,notPick);
        }

        else return dp[n][amount] = findMin(n-1,amount,coins,dp);


    }



    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        // vector<vector<int>> dp(n+1, vector<int>(amount +1, -1));

        // int ans =  findMin(n,amount,coins,dp);

        // return ans == 1e9 ? -1 : ans;

        

        // BOTTOM UP APPROACH

        vector<vector<int>> dp(n+1, vector<int>(amount +1, 0));

        for(int i=0; i<amount+1; i++){

            dp[0][i] = 1e9;
        }    

        for(int i=1; i<n+1; i++){

            for(int j=1; j<amount +1; j++){

                if(coins[i-1]<= j){

                    int pick = 1 + dp[i][j - coins[i-1]];
                    int notPick = dp[i-1][j];

                    dp[i][j] = min(pick,notPick);
                }

                else dp[i][j] = dp[i-1][j];
            }
        }

       int ans = dp[n][amount];

       return ans == 1e9 ? -1 : ans;

    }
};