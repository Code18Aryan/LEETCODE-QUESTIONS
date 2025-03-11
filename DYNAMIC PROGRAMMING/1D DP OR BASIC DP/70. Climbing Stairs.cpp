class Solution {

// private:

//      Recursion and top / down appraoch 

//    int numberOfWays(int n, vector<int> &dp){
        
//         if( n == 0 || n == 1) return 1;

//         if(dp[n] != -1) return dp[n];

//         int oneStep = numberOfWays(n-1,dp);
//         int twoStep = numberOfWays(n-2,dp);

//         return dp[n] = oneStep + twoStep;
//    }

public:
    int climbStairs(int n) {

        // Bottom Up approach 

        vector<int> dp(n+1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<n+1; i++){
             
             dp[i] = dp[i-1] + dp[i-2];

        }

        return dp[n];

        
        
    }
};