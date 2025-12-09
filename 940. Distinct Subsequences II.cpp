class Solution {
  public:
    int distinctSubseq(string &str) {
        
        unordered_map<char,int> mpp;
        vector<long long> dp(str.size()+1,0);
        dp[0] = 1;
        int mod = 1e9 + 7;
        
        for(int i=1; i<str.size()+1; i++){
            
           dp[i] = (2 * dp[i-1]) % mod;
           
           char ch = str[i-1];
           
           if(mpp.count(ch)){
               
               int j = mpp[ch];
               
               dp[i] = (dp[i] - dp[j-1] + mod)  % mod;
           }
            
           mpp[ch] = i; 
        }
        
        return dp[str.size()] % mod;
    }
};