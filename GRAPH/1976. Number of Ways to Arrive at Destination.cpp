class Solution {
public:

    typedef pair<long long,int> p;

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<vector<int>>> adj;

        int mod = 1e9 + 7;

        for(auto &x : roads){

            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});

        vector<long long> distance(n,LLONG_MAX);
        distance[0] = 0;

        vector<int> count(n,0);
        count[0] = 1;

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            long long  dist = it.first;
            int node = it.second;

            for(auto &x: adj[node]){

                int v = x[0];
                int wt = x[1];

                if(dist + wt < distance[v]){

                    count[v] = count[node] % mod;

                    distance[v] = dist + wt;
                    pq.push({distance[v],v});
                }

                else if(dist + wt == distance[v]){

                     count[v] = (count[v] + count[node]) % mod;
                }
            }
        }

        return count[n-1];
    }
};