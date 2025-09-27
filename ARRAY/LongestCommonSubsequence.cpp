#include<bits/stdc++.h>
using namespace std;



class Solution{
     
      public:


    int lcsRecursive(string x , string y , int n , int m){
         
          if(n == 0 || m == 0) return 0;

          if(x[n-1] == y[m-1]){
             
               return 1 + lcsRecursive(x,y,n-1,m-1);
          }

          else{ 
             
               return max(lcsRecursive(x,y,n,m-1) , lcsRecursive(x,y,n-1,m));
          }
    }

    int lcaMemo(string x , string y  , int n , int m , vector<vector<int>> &dp){

        if( n == 0 || m == 0) return 0;

        if(dp[n][m] != 0) return dp[n][m];

        if(x[n-1] == y[m-1]){
             
              return dp[n][m] = 1 + lcaMemo(x,y,n-1,m-1,dp);
        }

        else{
             
              return dp[n][m] = max( lcaMemo(x,y,n,m-1,dp) , lcaMemo(x,y,n-1,m,dp) );
        }
   
    }


    int lcaTabu(string x , string y , int n , int m){
         
         vector<vector<int>> dp(n+1 , vector<int>(m+1) );

         for(int i=0; i<n+1; i++){
             
              dp[i][0] = 0;
         }

         for(int i=0; i<m+1; i++){
             
              dp[0][i] = 0;
         }

         for(int i=1; i<n+1; i++){

             for(int j=1; j<m+1; j++){
                 
                  if(x[i-1] == y[j-1]){
                     
                      dp[i][j] = 1 + dp[i-1][j-1];
                  }

                  else{
                     
                      dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                  }
             }
         }

         return dp[n][m];
    }

};



int main(){
     
      Solution leetcode;


      string x = "abcufhj";
      string y = "abcfj";

      int n = x.size();
      int m = y.size();

      cout<<leetcode.lcaTabu(x,y,n,m);
}