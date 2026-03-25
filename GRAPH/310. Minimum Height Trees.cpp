class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> ans;

        if( n == 1) return {0};

        vector<int> adj[n];

        vector<int> indegree(n,0);

        queue<int>q;

        for(auto &x : edges){
             
              int u = x[0];
              int v = x[1];

              indegree[u]++;
              indegree[v]++;

              adj[u].push_back(v);
              adj[v].push_back(u);
        }

       

        for(int i=0; i<n; i++){
             
              if(indegree[i] == 1){
                 
                  q.push(i);
              }
        }

        while( n > 2){
             
              int size = q.size();

              n = n - size;

              while( size--){
                 
                  int u = q.front();
                  q.pop();

                  for(auto &v : adj[u]){
                     
                      indegree[v]--;

                      if( indegree[v] == 1){
                         
                          q.push(v);
                      }
                  }
              }
        }

        while(!q.empty()){
             
              ans.push_back(q.front());
              q.pop();
        }

        return ans;
        
    }
};