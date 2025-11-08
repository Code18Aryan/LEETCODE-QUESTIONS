class Solution {
  public:
    
    int findPath(int i, int j,int sum,vector<vector<int>>& mat,  vector<vector<vector<int>>> &dp){
        
        if(i < 0 || j < 0 || sum < 0) return 0;
        if(i == 0 && j == 0 && sum == mat[0][0]) return 1;
        if(dp[i][j][sum]!= -1) return dp[i][j][sum];
        
        int up = findPath(i-1,j,sum-mat[i][j],mat,dp);
        int left = findPath(i,j-1,sum-mat[i][j],mat,dp);
        
        return dp[i][j][sum] = up + left;
    }
  
    int numberOfPath(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(k+1,-1)));
        
        return findPath(n-1,m-1,k,mat,dp);
        
    }
};