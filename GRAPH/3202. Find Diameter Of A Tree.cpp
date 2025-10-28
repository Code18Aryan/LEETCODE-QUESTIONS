// Ques Link = https://www.geeksforgeeks.org/problems/diameter-of-a-graph/1
class Solution {
  public:
  
    pair<int,int> bfs(int start, unordered_map<int,vector<int>> &adj){
        
        unordered_map<int,bool> vis;
        vis[start] = 1;
        
        queue<int> q;
        q.push(start);
        
        int level = 0;
        int farthestNode = start;
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                int node = q.front();
                q.pop();
                
                farthestNode = node;
                
                for(auto &x : adj[node]){
                    
                    if(!vis[x]){
                        
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            
            if(!q.empty()) level++;
        }
        
        return {farthestNode,level};
    }
    
    int findDiameter(unordered_map<int,vector<int>> &adj){
        
        // Node distance
        pair<int,int> one = bfs(0,adj);
        pair<int,int> two = bfs(one.first,adj);
        
        return two.second;
    }
  
  
    int diameter(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        
        for(auto &x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = findDiameter(adj);
        
        return ans;
    }
};
