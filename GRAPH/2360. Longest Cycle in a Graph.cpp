class Solution {
public:

    int ans = -1;

    void exploreGraph(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &depth,
     unordered_map<int,vector<int>> &adj){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto &x : adj[node]){

            if(!vis[x]){

                depth[x] = depth[node] + 1;
                exploreGraph(x,vis,pathVis,depth,adj);
            }

            else if(pathVis[x]){

                int length = depth[node] - depth[x] + 1;
                ans = max(ans,length);
            }
        }

        pathVis[node] = 0;
        
    }

    
    int longestCycle(vector<int>& edges) {
        
        // Simple cycle detection with depth for calculating length
        
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            
            if(edges[i] != -1) adj[i].push_back(edges[i]);
            
        }

        vector<int> vis(edges.size(),0);
        vector<int> pathVis(edges.size(),0);
        vector<int> depth(edges.size(),1);

        for(int i=0; i<edges.size(); i++){

            if(!vis[i]){

                exploreGraph(i,vis,pathVis,depth,adj);
            }
        }

        return ans;
    }
};