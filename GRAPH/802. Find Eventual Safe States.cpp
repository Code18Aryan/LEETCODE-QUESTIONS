class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        unordered_map<int,vector<int>>adj;
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(graph.size(),0);

        for(int i=0; i<graph.size(); i++){
             
              for(auto &x: graph[i]){
                 
                  adj[x].push_back(i);
                  indegree[i]++;
              }
        }

        for(int i=0; i<indegree.size(); i++){
             
              if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
             
             int node = q.front();
             q.pop();

             ans.push_back(node);

             for(auto &x: adj[node]){
                 
                  indegree[x]--;

                  if(indegree[x] == 0) q.push(x);
             }
        }
        
        sort(ans.begin(),ans.end());

        return ans;
    }
};