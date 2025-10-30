class Solution {
  public:
    
    void markItVisited(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m, vector<int>&dr, vector<int>&dc){
        
        vis[row][col] = 1;
        
        for(int i=0; i<4; i++){
            
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            
            if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && !vis[nRow][nCol] && grid[nRow][nCol] == 'O'){
                
                markItVisited(nRow,nCol,vis,grid,n,m,dr,dc);
            }
        }
    }
    
    void usingBFS(int row, int col, vector<vector<int>> &vis,  vector<vector<char>> &grid, int n, int m, vector<int>&dr, vector<int>&dc){
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        vis[row][col] = 1;
        
        while(!q.empty()){
            
            auto x = q.front();
            q.pop();
            
            int r = x.first;
            int c = x.second;
            
            // we can also visit the cell here 
            
            for(int i=0; i<4; i++){
                
                int nRow = r + dr[i];
                int nCol = c + dc[i];
                
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && !vis[nRow][nCol] && grid[nRow][nCol] == 'O'){
                    
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
               }
            }
        }
    }
  
    void fill(vector<vector<char>>& grid) {
        
        // Approach -
        /* 
        The Boundary cell having 'O' could never be changed to 'X' and the cells having 'O' attached to it also be 
        never part of my answer. So, what we can do is to use bfs to dfs to mark the cells having '0' and run another two loop 
        through the matrix where we can find '0' where is not visited yet change it to 'X'
        */
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};
        
        for(int i=0; i<m; i++){
            
            if(grid[0][i] == 'O' && !vis[0][i]) markItVisited(0,i,vis,grid,n,m,dr,dc);
            if(grid[n-1][i] == 'O' && !vis[n-1][i]) usingBFS(n-1,i,vis,grid,n,m,dr,dc);
        }
        
        for(int i=1; i<n-1; i++){
            
            if(grid[i][0] == 'O' && !vis[i][0])usingBFS(i,0,vis,grid,n,m,dr,dc);
            if(grid[i][m-1] == 'O' && !vis[i][m-1])markItVisited(i,m-1,vis,grid,n,m,dr,dc);
        }
        
        for(int i=1; i<n-1; i++){
            
            for(int j=1; j<m-1; j++){
                
                if(grid[i][j] == 'O' && !vis[i][j]){
                    
                    grid[i][j] = 'X';
                }
            }
        }
        
        
    }
};