class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance( m , vector<int>(n,0));
        vector<vector<int>> vis(m , vector<int>(n,0));

        queue<pair<pair<int,int>, int>> q;

        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};
        

        for(int i=0; i<m; i++){
             
             for(int j=0; j<n; j++){
                 
                  if(mat[i][j] == 0){
                     
                      q.push({{i,j},0});
                      vis[i][j] = 1;
                  }
             }
        }

        while(!q.empty()){
             
              int row = q.front().first.first;
              int col = q.front().first.second;

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