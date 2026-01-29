class Solution {
public:

    // First Approach using dijsktra Algo

    typedef pair<int,int> p;
    typedef long long ll;

    int findCost(char src, char dest, unordered_map<int,vector<vector<int>>> &adj){

        int start = src - 'a';
        int end =  dest - 'a';

        vector<int> distance(26,1e9);
        distance[start] = 0;

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,start});

        while(!pq.empty()){

            auto &it = pq.top();
            int node = it.second;
            int dist = it.first;
            pq.pop();

            if(dist > distance[node]) continue;

            for(auto &x : adj[node]){

                int v = x[0];
                int wt = x[1];

                if(dist + wt < distance[v]){

                    distance[v] = dist + wt;
                    pq.push({dist + wt, v});
                }
            }

        }

        return distance[end] == 1e9 ? -1 : distance[end];
    }


    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

       /* unordered_map<int,vector<vector<int>>> adj;
        ll totalCost = 0LL;

        for(int i=0; i<original.size(); i++){

            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        for(int i=0; i<source.size(); i++){

            if(source[i] != target[i]){

                int cost = findCost(source[i],target[i],adj);

                if(cost == -1) return -1;

                totalCost += cost;
            }
        }

        return totalCost;  */

        ll totalCost = 0;
        const ll INF = 1e18;

        vector<vector<ll>> distance(26,vector<ll>(26,INF));

        for(int i=0; i<26; i++){

            distance[i][i] = 0;
        }

        for(int i=0; i<original.size(); i++){

            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            distance[u][v] = min((ll)cost[i],distance[u][v]);
        }

        for(int k=0; k<26; k++){

            for(int i=0; i<26; i++){

                for(int j=0; j<26; j++){

                    if(distance[i][k] < INF && distance[k][j] < INF){

                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);

                    }
                }
            }
        }

        for(int i=0; i<source.size(); i++){

            if(source[i] != target[i]){

                ll cost = distance[source[i] - 'a'][target[i] - 'a'];

                if(cost == INF) return -1;

                totalCost += cost;

            }

        }


        return totalCost;
        
    }
};