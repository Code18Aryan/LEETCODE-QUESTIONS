class Solution {
  public:
    
    int solve(int index, int canBuy, vector<int>&arr, int k, vector<vector<int>>&dp){
        
        if(index >= arr.size()){
            
            return 0;
        }
        
        if(dp[canBuy][index] != -1) return dp[canBuy][index];
        
        int profit = 0;
        
        if(canBuy){
            
            profit = max(-arr[index] + solve(index+1,0,arr,k,dp), solve(index+1,1,arr,k,dp));
        }
        
        else{
            
            profit = max(arr[index] - k+ solve(index+1,1,arr,k,dp), solve(index+1,0,arr,k,dp));
        }
        m
        return dp[canBuy][index] = profit;
    }
  
    int maxProfit(vector<int>& arr, int k) {
        
        int n = arr.size();
        
       // memset(dp,-1,sizeof(dp));
       
       vector<vector<int>> dp(2, vector<int>(n,-1));
        
        
        return solve(0,1,arr,k,dp);
        
    }
};