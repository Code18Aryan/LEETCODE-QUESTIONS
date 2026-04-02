class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& coins, int skip,  vector<vector<vector<int>>> &dp){

        if(i < 0 || j < 0) return -1e9;

        if(i == 0 && j == 0){

            if(coins[0][0] < 0 && skip) return max(0,coins[0][0]);

            return coins[0][0];
        }

        if(dp[i][j][skip] != INT_MIN) return dp[i][j][skip];

        int up = 0, left = 0;

        if(coins[i][j] < 0 && skip){

            int skip_up = solve(i-1,j,coins,skip-1,dp);
            int skip_left = solve(i,j-1,coins,skip-1,dp);

            int take_up = coins[i][j] + solve(i-1,j,coins,skip,dp);
            int take_left = coins[i][j] + solve(i,j-1,coins,skip,dp);

            return dp[i][j][skip] = max({skip_up, skip_left, take_up, take_left});
        }

        else{

            up += coins[i][j] + solve(i-1,j,coins,skip,dp);
            left += coins[i][j] + solve(i,j-1,coins,skip,dp);
        }

        return dp[i][j][skip] = max(up,left);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,INT_MIN)));

        return solve(n-1,m-1,coins,2,dp);
    }
};