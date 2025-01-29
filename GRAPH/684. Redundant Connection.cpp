class Solution {
public:

    bool hasCycle(int src, unordered_map<int,vector<int>> adj){

        unordered_map<int,bool> vis;
        vis[src] = 1;

        queue<pair<int,int>> q;
        q.push({src,-1});

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto &adjNode : adj[node]){

                    if(!vis[adjNode]){

                        vis[adjNode] = 1;
                        q.push({adjNode,node});
                    }

                    else if(adjNode != parent) return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> adj;

        for(auto &x : edges){

            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            if(hasCycle(u,adj)) return {u,v};

        }

        return {-1,-1};
    }
};