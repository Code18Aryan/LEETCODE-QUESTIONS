class Solution {

private:

  string reverseString(string s){
     
      int n = s.size();

      int low = 0;
      int high = n-1;

      while( low < high){
         
          swap(s[low] , s[high]);
          
          low++; high--;
      }

      return s;
  }

  bool isPalindrome(string s){

      int n = s.size();
     
      if(n == 0) return true;
      if(n == 1) return true;

      int low = 0;
      int high = s.size()-1;

      while(low < high){ 

           if(s[low] != s[high]) return false;

           low++; high--;
      }

      return true;
  }

  string lcs(string x , string y){
     
      int n = x.size();
      int m = y.size();

      int maxLength = 0;
      string ans = "";

      int dp[n+1][m+1];

      for(int i=0; i<n+1; i++){
         
          for(int j=0; j<m+1; j++){
             
               if( i == 0 || j == 0){
                 
                  dp[i][j] = 0;
               }
          }
      }

      for(int i=1; i<n+1; i++){

         for(int j=1; j<m+1; j++){
             
              if(x[i-1] == y[j-1]){
                 
                  dp[i][j] = 1 + dp[i-1][j-1];
              }

              else{
                 
                  dp[i][j] = 0;
              }

              if(dp[i][j] > maxLength){
                 
                  string first = x.substr( i - dp[i][j] , dp[i][j]);

                if(isPalindrome(first)){

                     ans = first;

                     maxLength = dp[i][j];
                }
              }
         }
      }

      return ans;
  }

public:
    string longestPalindrome(string s) {

        string s1 = s;
        string s2 = reverseString(s);

        return lcs(s1,s2);
        
    }
};