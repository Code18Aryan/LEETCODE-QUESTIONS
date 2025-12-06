class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,vector<vector<int>>> adj;

        for(auto x : flights){
            
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v,wt});
        }

        vector<int>distance(n,1e9);
        distance[src] = 0;

        queue<pair<int,pair<int,int>>>q; // We dont need min heap as we judge on the basis of stops and stops increase one by one 
        q.push({0,{src,0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int dist = it.second.second;

            if(stops > k) continue;

            for(auto x : adj[node]){

                int v = x[0];
                int edwt = x[1];

                if(dist + edwt < distance[v] && stops <= k){

                    distance[v] = dist + edwt;
                    q.push({stops + 1, {v,distance[v]}});
                }
            }
        }

        return distance[dst] == 1e9 ? -1 : distance[dst];
    }

};
