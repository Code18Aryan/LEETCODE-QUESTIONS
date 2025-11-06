class Solution {
  public:
    int numberOfWays(int n) {
        
        if(n == 1 || n == 2) return n;
        
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++){
            
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};