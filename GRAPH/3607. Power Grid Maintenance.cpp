class Solution {
public:

    void dfs(int node, unordered_map<int,vector<int>> &adj,unordered_map<int,bool>&vis,unordered_map<int,set<int>> &powerGrid,int &componentId, unordered_map<int,int> &mpp){

        vis[node] = 1;
        powerGrid[componentId].insert(node);
        mpp[node] = componentId;

        for(auto &x : adj[node]){

            if(!vis[x]){

                dfs(x,adj,vis,powerGrid,componentId,mpp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        unordered_map<int,vector<int>> adj;
        unordered_map<int,set<int>> powerGrid;
        unordered_map<int,bool> vis;
        vector<int> ans;
        unordered_map<int,int> StationToComponent;

        for(auto &x : connections){

            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int componentId = 1;

        for(int i=1; i<=c; i++){

            if(!vis[i]){

                dfs(i,adj,vis,powerGrid,componentId,StationToComponent);
                componentId++;
            }
        }

        for(auto &x : queries){

            int action = x[0];
            int station = x[1];
            int componentId = StationToComponent[station];

            if(action == 2){

                powerGrid[componentId].erase(station);
            }

            else{

                if(powerGrid[componentId].find(station) != powerGrid[componentId].end()){

                    ans.push_back(station);
                }

                else if(powerGrid[componentId].empty()) ans.push_back(-1);

                else ans.push_back(*powerGrid[componentId].begin());

            }
        }

        return ans;
    }
};