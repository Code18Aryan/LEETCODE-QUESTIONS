
class Solution {
  public:
  
    int solve(int i, int j, vector<int>&arr, vector<vector<int>> &dp){
        
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        
        for(int k=i; k<=j-1; k++){
            
            int cost = arr[i-1] * arr[k] * arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
            
            if(cost < mini) mini = cost;
        }
        
        return dp[i][j] = mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        
        // vector<vector<int>> dp(101, vector<int>(101,-1));
        
        // return solve(1,n-1,arr,dp);
        
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        for(int i=n-1; i>=1; i--){
            
            for(int j=i+1; j<n; j++){
                
                int mini = 1e9;
                
                for(int k=i; k<=j-1; k++){
                    
                    int cost = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    
                    if(cost < mini) mini = cost;
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
        
        
    }
};



// } Driver Code Ends