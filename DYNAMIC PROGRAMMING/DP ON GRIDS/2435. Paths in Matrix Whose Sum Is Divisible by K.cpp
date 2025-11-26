// Ques Link - https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

class Solution {
public:

    int mod = 1e9 + 7;
    typedef long long ll;

    int findNumberOfPaths(int i, int j, ll sum, vector<vector<int>>&grid, int k, vector<vector<vector<int>>> &dp){

        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0){

            if((sum + grid[i][j] )% k == 0){
            
                return 1;
            }

            return 0;
        }

        if(dp[i][j][sum % k] != -1) return dp[i][j][sum % k];

        int up = findNumberOfPaths(i-1,j,sum + grid[i][j],grid,k,dp) % mod;
        int left = findNumberOfPaths(i,j-1,sum + grid[i][j],grid,k,dp) % mod;

        return dp[i][j][sum % k] = (up + left) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        ll sum = 0;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int>(k,-1)));

        return findNumberOfPaths(n-1,m-1,sum,grid,k,dp);
    }

};
