// gfg Link - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
  
    
    void findPath(int row, int col,int n, string path, vector<vector<int>>& vis, vector<vector<int>>& maze, vector<int>&dr, vector<int>&dc, vector<string>&ans){
        
        if(row == n-1 && col == n-1){
            
            ans.push_back(path);
            
            return;
        }
        
        string dir = "DLRU";
        
        for(int i=0; i<4; i++){
            
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if(nr < n && nr >= 0 && nc < n && nc >= 0 && !vis[nr][nc] && maze[nr][nc] == 1){
                
                vis[nr][nc] = 1;
                
                findPath(nr,nc,n,path + dir[i], vis,maze,dr,dc,ans);
                
                vis[nr][nc] = 0;
            }
        }
    }
  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       
       int n = maze.size();
       
       vector<string> ans;
       
       if(!maze[0][0] || !maze[n-1][n-1]) return ans;
       
       vector<int> dr = {+1,0,0,-1};
       vector<int> dc = {0,-1,+1,0};
       
       // In this test case it doesnot matter  if we visit current i.e 0 0 before calling the function and after vis nr nc 
       // or vis[row][col] then call for nr nc 
       
       
       vector<vector<int>> vis(n, vector<int>(n,0));
       
       vis[0][0] = 1;
       
        findPath(0,0,n,"",vis,maze,dr,dc,ans);
        
        return ans;
        
    }
};
