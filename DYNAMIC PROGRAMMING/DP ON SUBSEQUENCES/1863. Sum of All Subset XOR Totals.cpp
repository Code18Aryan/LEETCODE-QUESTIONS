class Solution {
  public:
    
    
    int solve(int index, int sum, vector<int>&nums, vector<vector<int>>&dp){
        
        if(index >= nums.size()){
            
            return sum;
        }
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int take = solve(index+1,sum ^ nums[index],nums,dp);
        int notTake = solve(index+1,sum,nums,dp);
        
        return dp[index][sum] = take + notTake;
    }
  
    int subsetXORSum(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(2e3+1,-1));
        
        int sum = 0;
        
        return solve(0,sum,arr,dp);
    }
};