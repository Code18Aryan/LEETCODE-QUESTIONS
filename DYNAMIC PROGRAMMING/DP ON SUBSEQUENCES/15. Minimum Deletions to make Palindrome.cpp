class Solution {
  public:
  
    int solve(int m, int n, string &a, string &b, vector<vector<int>> &dp){
        
        if(m == 0 || n == 0){
            
            return 0;
        }
        
        if(dp[m][n] != -1){
            
            return dp[m][n];
        }
        
        if(a[m-1] == b[n-1]){
            
            return dp[m][n] = 1 + solve(m-1,n-1,a,b,dp);
        }
        
        else{
            
            return dp[m][n] = max(solve(m-1,n,a,b,dp) , solve(m,n-1,a,b,dp));
        }
    }
  
    int minDeletions(string s) {
        
       
       string t = s;
       
       reverse(t.begin(),t.end());
       
       int n = s.size();
       
    //   vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
       
    //   return s.size() - solve(s.size(),s.size(),s,t,dp);
    
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        for(int i=1; i<n+1; i++){
            
            for(int j=1; j<n+1; j++){
                
                if(s[i-1] == t[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else{
                    
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
       
       
       return n - dp[n][n];
        
    }
};