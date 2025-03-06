
class Solution {
  public:

    
    int solve(int n, int m, string x, string y,vector<vector<int>> &dp){
        
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(x[n-1] == y[m-1]){
            
            return dp[n][m] = 1 + solve(n-1,m-1,x,y,dp);
        }
        
        else{
            
            return dp[n][m] = max(solve(n-1,m,x,y,dp), solve(n,m-1,x,y,dp));
        }
        
    }
  
  
    int lcs(string &s1, string &s2) {
        
        int n = s1.size();
        int m = s2.size();
        
       // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
       // return solve(n,m,s1,s2,dp);
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<n+1; i++){
            
            for(int j=1; j<m+1; j++){
                
                if(s1[i-1] == s2[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends