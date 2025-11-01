class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<int> topoSort;

        vector<int> adj[n];

        queue<int> q;

        vector<int> indegree(n,0);

        for(auto x : prerequisites){
             
              int u = x[0];
              int v = x[1];

              adj[v].push_back(u);
        }

        for(int i=0; i<n; i++){
             
              for(auto x : adj[i]){
                 
                  indegree[x]++;
              }
        }

        for(int i=0; i<n; i++){
             
              if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
             
              int node = q.front();
              q.pop();

              topoSort.push_back(node);

              for(auto x : adj[node]){
                 
                  indegree[x]--;

                  if(indegree[x] == 0) q.push(x);
              }
        }

        if(topoSort.size() == n) return topoSort;

        return {};


        
    }
};