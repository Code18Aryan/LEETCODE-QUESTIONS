class Solution {
public:

    vector<int> changeRow = {-1,0,+1,0};
    vector<int> changeCol = {0,+1,0,-1};

    int findArea(int r, int c, int n, vector<vector<int>>& grid, vector<vector<int>>& vis,int index){

        vis[r][c] = 1;
        
        queue<pair<int,int>> q;
        q.push({r,c});

        int area = 0;

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            area++;

            grid[row][col] = index;

            for(int i=0; i<4; i++){

                int nRow = row + changeRow[i];
                int nCol = col + changeCol[i];

                if(nRow < n && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){

                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
               
        }

        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        int maxArea = 0;

        unordered_map<int,int> mpp;

        int index = 2;

        vector<vector<int>> vis(n,vector<int>(n,0));

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 1 && !vis[i][j]){

                    int area = findArea(i,j,n,grid,vis,index);

                    mpp[index] = area;

                    index++;
                }
            }
        }

        
        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 0){

                    int area = 1;

                    unordered_set<int>st;

                    for(int k=0; k<4; k++){

                        int nRow = i + changeRow[k];
                        int nCol = j + changeCol[k];

                        if(nRow < n && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] != 0){

                            st.insert(grid[nRow][nCol]);
                        }
                    }

                    for(auto x : st){

                        area += mpp[x];
                    }

                    maxArea = max(maxArea, area);


                }
            }
        }

        return maxArea == 0 ? n*n : maxArea;
        
    }
};