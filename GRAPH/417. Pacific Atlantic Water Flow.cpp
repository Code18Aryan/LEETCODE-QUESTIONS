// Ques Link - https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

class Solution {
public:

    vector<int> dr = {-1,0,+1,0};
    vector<int> dc = {0,+1,0,-1};

    bool isValid(int row, int col, int n, int m){

        if(row < n && col < m && row >= 0 && col >= 0) return true;

        return false;
    }

    void canVisit(int row, int col, int prev,vector<vector<int>>& heights, vector<vector<int>>& vis, int n, int m){

        vis[row][col] = 1;

        for(int i=0; i<4; i++){

            int nr = row + dr[i];
            int nc = col + dc[i];

            if(isValid(nr,nc,n,m) && heights[nr][nc] >= prev && !vis[nr][nc]){

                canVisit(nr,nc,heights[nr][nc],heights,vis,n,m);
            }
        }

    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        if(n == 0 || m == 0) return ans;

        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0; i<m; i++){

            canVisit(0,i,heights[0][i],heights,pacific,n,m);
            canVisit(n-1,i,heights[n-1][i],heights,atlantic,n,m);
        }

        for(int i=0; i<n; i++){

            canVisit(i,0,heights[i][0],heights,pacific,n,m);
            canVisit(i,m-1,heights[i][m-1],heights,atlantic,n,m);
        }

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(pacific[i][j]  && atlantic[i][j]){

                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }

};
