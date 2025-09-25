class Solution {

private:

    int getMinPath(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){

        if(i == n || j == n) return 1e9;
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + getMinPath(i+1,j,n,triangle,dp);
        int downRight = triangle[i][j] + getMinPath(i+1,j+1,n,triangle,dp);

        return dp[i][j] = min(down,downRight);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //1st Approach -> they asked about the min path sum from top to bottom
        // greedy approach failed because what if we miss any greater number which can be answer
        // that is because of we choose a number greater in prev path 
        // so we try all ways and choose use desired answer
        // whenever we see all ways think of recursion

        // Using recursion give tle with few test cases passed 

        //2nd Approach we can memoize it using 2d vector 

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n,-1));

       // return getMinPath(0,0,n,triangle,dp);

       // Memoization still gives TLE with 27/46 test cases passed

       //3rd Approach using bottom up dp

       for(int i=0; i<n; i++) dp[n-1][i] = triangle[n-1][i];

        for(int i=n-2; i>=0; i--){

            for(int j=i; j>=0; j--){

                int down = triangle[i][j] + dp[i+1][j];
                int downRight = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,downRight);
            }
       }

       return dp[0][0];
       
    }
};