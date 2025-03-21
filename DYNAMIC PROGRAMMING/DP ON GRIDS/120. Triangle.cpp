class Solution {
public:

    int solve(int row , int col , int n , vector<vector<int>>& nums, vector<vector<int>>& dp){
         
          if( row == n-1) return nums[row][col];
          if(row >= n || col >= n) return 1e9;

          if(dp[row][col] != -1)  return dp[row][col];

          int down = nums[row][col] + solve(row + 1 , col , n, nums,dp);

          int dia = nums[row][col] + solve(row + 1 , col + 1 ,n, nums , dp);

          return dp[row][col] = min(down , dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        
        return solve(0,0,triangle,dp);

        if(n == 1) return triangle[0][0];

        vector<vector<int>> dp( n , vector<int>( n));

        for(int j=0; j<n; j++){
             
             dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
             
              for(int j=i; j>=0; j--){
                 
                  int up = triangle[i][j] + dp[i+1][j];
                  int dia = triangle[i][j] + dp[i + 1][j +1];

                  dp[i][j] = min(up , dia);
              }
        }

         return dp[0][0];
        
    }
};