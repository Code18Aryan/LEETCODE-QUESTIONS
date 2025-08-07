class Solution {
public:

    int findMinSum(int i, int j, int n , int m, vector<vector<int>>& matrix, vector<vector<int>>& dp ){

        if( i < 0 || i > n-1 || j < 0 || j > m-1) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + findMinSum(i-1,j,n,m,matrix,dp);
        int left = matrix[i][j] + findMinSum(i-1,j-1,n,m,matrix,dp);
        int right = matrix[i][j] + findMinSum(i-1,j+1,n,m,matrix,dp);

        return dp[i][j] = min({up,left,right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        int minimumPathSum = 1e9;

        for(int i=0; i<m; i++){

            int distance = findMinSum(n-1,i,n,m,matrix,dp);

            minimumPathSum = min(minimumPathSum,distance);
        }

        return minimumPathSum;
    }
};