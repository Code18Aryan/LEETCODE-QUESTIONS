// Ques Link - https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1

class DSU{
    
    public:
    
    vector<int> parent;
    vector<int> size;
    
    DSU(int n){
        
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i=0; i<=n; i++){
            
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        
        if(parent[node] == node) return node;
        
        
        return parent[node] = findParent(parent[node]);
    }
    
    void merge(int u, int v){
        
        int up_u = findParent(u);
        int up_v = findParent(v);
        
        if(up_u == up_v) return;
        
        if(size[up_u] < size[up_v]){
            
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        
        else{
            
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }

};

class Solution {
  public:
  
    int findMst(int v,int notTake, vector<vector<int>> &edges){
        
        int mstWeight = 0;
        int edgeTaken = 0;
        
        DSU dsu(v);
        
        for(int i=0; i<edges.size(); i++){
            
            if(i == notTake) continue;
            
            int wt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            if(dsu.findParent(u) != dsu.findParent(v)){
                
                dsu.merge(u,v);
                mstWeight += wt;
                edgeTaken++;
            }
        }
        
        return (edgeTaken == v-1) ? mstWeight : -1;
    }
    
    int findMstt(int v,vector<vector<int>> &edges, vector<int>&usedEdge){
        
        int mstWeight = 0;
        int edgeTaken = 0;
        
        DSU dsu(v);
        
        for(int i=0; i<edges.size(); i++){
            
            int wt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            if(dsu.findParent(u) != dsu.findParent(v)){
                
                dsu.merge(u,v);
                mstWeight += wt;
                edgeTaken++;
                usedEdge[i] = 1;
            }
        }
        
        return (edgeTaken == v-1) ? mstWeight : -1;
    }
  
    int secondMST(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj;
        int ans = 1e9;
        
        for(auto x : edges){
            
            adj.push_back({x[2],x[0],x[1]});
        }
        
        sort(adj.begin(),adj.end());
        
        vector<int> usedEdge(edges.size(),0);
        
        int originalMstWeight = findMstt(V,adj,usedEdge);
        
        for(int i=0; i<edges.size(); i++){
            
            if(usedEdge[i]){
                
                int newMstWeight = findMst(V,i,adj);
                
                if(newMstWeight != -1 && newMstWeight > originalMstWeight){
                    
                    ans = min(ans, newMstWeight);
                }
            }
        }
        
        return ans == 1e9 ? -1 : ans;
        
    }
};
