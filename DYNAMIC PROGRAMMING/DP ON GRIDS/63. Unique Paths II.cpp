#include <bits/stdc++.h>
using namespace std;

class A{

    public:

    int findUniquePath(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){

        if(i == 0 && j == 0) return 1;
        if(i < 0  || j < 0) return 0;
        if(i >=0 && i < n &&  j >= 0 && j < m && mat[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up =  findUniquePath(i-1,j,n,m,mat,dp);
        int left = findUniquePath(i,j-1,n,m,mat,dp);

        return dp[i][j] = up + left;
    }

    int findUniquePathUsingBottomUp(vector<vector<int>> &mat, int n, int m, vector<vector<int>> &dp){

        for(int i=0; i<n; i++){

            for(int j=0; j<m;j++){

                if(i == 0 && j == 0) dp[i][j] = 1;

                else if(mat[i][j] == 1) dp[i][j] = 0;

                else{

                    int left = 0, up = 0;

                    if(i > 0) up += dp[i-1][j];

                    if(j > 0) left += dp[i][j-1];

                    dp[i][j] = up + left;
                }


            }
        }

        return dp[n-1][m-1];
        
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        A leetcode;

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));

        //return leetcode.findUniquePath(n-1,m-1,n,m,obstacleGrid,dp);

        return leetcode.findUniquePathUsingBottomUp(obstacleGrid,n,m,dp);


    }
};