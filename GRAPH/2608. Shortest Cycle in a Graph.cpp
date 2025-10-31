// Ques Link - https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

class Solution {
public:
    int findShortestCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        
        for(auto &x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = 1e9;
        
        for(int i=0; i<V; i++){
            
            // we dont really need vis array because the dist arary will done the job for us 
            queue<pair<int,pair<int,int>>> q;
            q.push({i,{-1,0}});
            
            vector<int> dist(V,-1);
            dist[i] = 0;
            
            while(!q.empty()){
                
                auto it = q.front();
                q.pop();
        
                
                int node = it.first;
                int parent = it.second.first;
                int level = it.second.second;
                
                for(auto &x : adj[node]){
                    
                    if(dist[x] == -1){
                        
                        dist[x] = level + 1;
                        q.push({x,{node,level + 1}});
                    }
                    
                    else if(x != parent){
                        
                        int cycleDistance = dist[node] + dist[x] + 1;
                        
                        ans = min(ans,cycleDistance);
                    }
                }
            }
        }
        
        return ans == 1e9 ? -1 : ans;
    }

};
