
class Solution {
  public:
  
  
    void dfs(int node, unordered_map<int,vector<int>> adj, vector<int>&vis, stack<int>&st){
        
        vis[node] = 1;
        
        for(auto adjNode : adj[node]){
            
            if(!vis[adjNode]){
                
                dfs(adjNode,adj,vis,st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> topoSortUsingDFS(int V, vector<vector<int>>& edges) {
      
      unordered_map<int,vector<int>> adj;
      
      for(auto x: edges){
          
          adj[x[0]].push_back(x[1]);
      }
      
      stack<int> st;
      vector<int> vis(V,0);
      
      for(int i=0; i<V; i++){
          
          if(!vis[i]){
              
              dfs(i,adj,vis,st);
          }
      }
      
      vector<int> ans;
      
      while(!st.empty()){
          
          ans.push_back(st.top());
          st.pop();
      }
      
      return ans;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
      
      unordered_map<int,vector<int>> adj;
      vector<int> indegree(V,0);
      vector<int> ans;
      queue<int> q;
      
      for(auto x: edges){
          
          adj[x[0]].push_back(x[1]);
          indegree[x[1]]++;
          
      }
      
      for(int i=0; i<V; i++){
          
          if(indegree[i] == 0){
              
              q.push(i);
          }
      }
      
      while(!q.empty()){
          
          int node = q.front();
          q.pop();
          
          ans.push_back(node);
          
          for(auto x : adj[node]){
              
              indegree[x]--;
              
              if(indegree[x] == 0){
                  
                  q.push(x);
              }
          }
      }
      
      
      return ans;
      
    }
    
};