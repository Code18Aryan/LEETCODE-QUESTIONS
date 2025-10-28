// Ques Link - https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        // For Storing Distance
        vector<vector<int>> distance( m , vector<int>(n,0));
        
        // Visited array for not visiting the same grid again
        vector<vector<int>> vis(m , vector<int>(n,0));

        // BFS traversal
        queue<pair<pair<int,int>, int>> q;

        // Using for traversal to 4 Directions
        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};
        

        for(int i=0; i<m; i++){
             
             for(int j=0; j<n; j++){
                 
                  if(mat[i][j] == 0){
                     
                      q.push({{i,j},0});
                      // Make it visited 
                      vis[i][j] = 1;
                  }
             }
        }

        while(!q.empty()){
             
              int row = q.front().first.first;
              int col = q.front().first.second;

              // add dist to the given row col.
              // We are inserting the distance here because let's suppose we are at the final cell and carrying the distance we check 4 direction but all are not valid
              // since we dont enter the neigbour cell the if condition never runs 
              int dist = q.front().second;

              distance[row][col] = dist;

              q.pop();

              for(int i=0; i<4; i++){
                 
                  int nRow = row + changeRow[i];
                  int nCol = col + changeCol[i];

                  if(nRow < m && nRow >= 0 && nCol < n && nCol >= 0 && mat[nRow][nCol] == 1 && !vis[nRow][nCol]){
                     
                      q.push({{nRow,nCol}, dist +1});
                      vis[nRow][nCol] = 1;
                  }
              }
        }

        return distance;
        
    }

};
