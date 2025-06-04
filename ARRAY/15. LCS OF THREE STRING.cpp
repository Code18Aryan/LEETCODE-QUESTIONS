class Solution {
  public:
    
    string lcs(string &s1, string &s2){
        
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<=m; j++){
                
                if(s1[i-1] == s2[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int i = n;
        int j = m;
        
        string ans = "";
        
        while( i > 0 && j > 0){
            
            if(s1[i-1] == s2[j-1]){
                
                ans += s1[i-1];
                i--;
                j--;
            }
            
            else{
                
                if(dp[i-1][j] > dp[i][j-1]){
                    
                    i--;
                }
                
                else{
                    
                    j--;
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
  
  
    int lcsOf3(string& s1, string& s2, string& s3) {
       
       string first = lcs(s1,s2);
       
       string second = lcs(first,s3);
       
       //return second.size();
       
       int n = s1.size();
       int m = s2.size();
       int o = s3.size();
       
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int>(o+1,0)));
       
       for(int i=1; i<=n; i++){
           
           for(int j=1; j<=m; j++){
               
               for(int k=1; k<=o; k++){
                   
                   if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]){
                       
                       dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                   }
                   
                   else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
               }
           }
       }
       
       return dp[n][m][o];
       
    }
};
