class Solution {
  public:
  
    void explorePath(int src, int dest, int &cnt, unordered_map<int,vector<int>> &adj,vector<int>&vis, vector<int>&pathVis){
        
        if(src == dest){
            
            cnt++;
            return;
        }
        
        for(auto x : adj[src]){
            
           if(!pathVis[x]){
               
               vis[src] = 1;
               pathVis[src] = 1;
               
               explorePath(x,dest,cnt,adj,vis,pathVis);
               
               pathVis[src] = 0;
           }
        }
    }
  
  
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(V,0);
        
        for(auto x: edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            
            indegree[v]++;
        }
        
        // vector<int> pathVis(V,0);
        // vector<int> vis(V,0);
        // int cnt = 0;
        
        // explorePath(src,dest,cnt,adj,vis,pathVis);
        
        // return cnt;
        
        vector<int> dp(V,0);
        dp[src] = 1;
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            
            if(indegree[i] == 0) q.push(i);
        }
    
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adj[node]){
                
                dp[adjNode] += dp[node];
                
                indegree[adjNode]--;
                
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
            
        }
        
        
        return dp[dest];
    }
};