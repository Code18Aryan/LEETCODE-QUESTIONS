class Solution {
public:

    // Question asked find max gold in the path means start from one and end at one point -> single direction
    // whenever question find all ways always use recursion for finding it and store the optimal answer

    int maxGold = 0;

    void findMaxGold(int row, int col, int n, int m, int &gold, vector<int>&dr, vector<int>&dc, vector<vector<int>> &grid, vector<vector<int>> &vis){

        vis[row][col] = 1;
        gold += grid[row][col];

        for(int i=0; i<4; i++){

            int nRow = row + dr[i];
            int nCol = col + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] != 0){

                findMaxGold(nRow,nCol,n,m,gold,dr,dc,grid,vis);
            }
        }

        maxGold = max(maxGold,gold);
        vis[row][col] = 0;
        gold -= grid[row][col];
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(!vis[i][j] && grid[i][j] != 0){
                    
                    int gold = 0;
                    findMaxGold(i,j,n,m,gold,dr,dc,grid,vis);
                }
            }
        }

        return maxGold;
    }
};