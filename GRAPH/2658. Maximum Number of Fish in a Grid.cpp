class Solution {
public:
    int findMaxi(int m, int n, int row, int col, vector<vector<int>>& grid,
                 vector<vector<int>>& vis) {

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int ans = 0;

        int changeRow[] = {-1, 0, +1, 0};
        int changeCol[] = {0, +1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            ans += grid[r][c];

            for (int i = 0; i < 4; i++) {

                int nRow = r + changeRow[i];
                int nCol = c + changeCol[i];

                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] != 0 && !vis[nRow][nCol]){

                        vis[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                    }
            }


        }


        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxiFish = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0 && !vis[i][j]) {

                    int ans = findMaxi(m, n, i, j, grid, vis);

                    maxiFish = max(maxiFish, ans);
                }
            }
        }
        return maxiFish;
    }
};



//   SOLVING USING DFS 


class Solution {
public:

    int solve(int row, int col, int m, int n,vector<vector<int>>& grid, vector<vector<int>>& vis,vector<int>&changeRow,vector<int>&changeCol){

        vis[row][col] = 1;

        int ans = grid[row][col];

        for(int i=0; i<4; i++){

            int nRow = row + changeRow[i];
            int nCol = col + changeCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] != 0 && !vis[nRow][nCol]){

                ans += solve(nRow,nCol,m,n,grid,vis,changeRow,changeCol);
            }
        }

        return ans;
    }


    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        int maxFish = 0;

        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] != 0 && !vis[i][j]){

                int currentFish = solve(i,j,m,n,grid,vis,changeRow,changeCol);

                maxFish = max(maxFish,currentFish);

                }
            }
        }

        return maxFish;
        
    }
};