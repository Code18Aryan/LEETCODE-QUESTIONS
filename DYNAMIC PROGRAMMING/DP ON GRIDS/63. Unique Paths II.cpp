class Solution {
  public:
  
    int solve(int i, int j, vector<vector<int>>dp, vector<vector<int>>&grid){
        
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 0;
    
        int left = 0;
        
        if(grid[i][j] == 0 && i >= 0 && j >= 0){
            
            up += solve(i-1,j,dp,grid);
        }
        
        if(grid[i][j] == 0 && i >= 0 && j >= 0){
            
            left += solve(i,j-1,dp,grid);
        }
        
        return dp[i][j] = up + left;
    }
  
  
    int uniquePaths(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        
        // return solve(n-1,m-1,dp,grid);
        
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        dp[0][0] = 1;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 1){
                    
                    dp[i][j] = 0;
                    continue;
                }
                
                if(i == 0 && j == 0) continue;
            
                    
                    int up = 0;
                    int left = 0;
                    
                    if(i > 0){
                        
                        up += dp[i-1][j];
                    }
                    
                    if(j > 0){
                        
                        left += dp[i][j-1];
                    }
                    
                    dp[i][j] = up + left;
                
            }
        }
        
        
        return dp[n-1][m-1];
        
        
        
    }
};