class Solution {
public:

    int dp[70+1][70+1][70+1];

    int findMaxCherry(int r, int c1, int c2, int n, int m, vector<vector<int>> &grid){

        if(c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) return -1e9;
        if(r == n-1){

            if(c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int currentValue = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];

        int nextBest = -1e9;

        for(int dc1=-1; dc1<=1; dc1++){

            for(int dc2=-1; dc2<=1; dc2++){

                int value = findMaxCherry(r+1,c1+dc1,c2+dc2,n,m,grid);

                nextBest = max(nextBest,value);
            }
        }

        return dp[r][c1][c2] = currentValue + nextBest;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        memset(dp,-1,sizeof(dp));

        return findMaxCherry(0,0,m-1,n,m,grid);
    }
};