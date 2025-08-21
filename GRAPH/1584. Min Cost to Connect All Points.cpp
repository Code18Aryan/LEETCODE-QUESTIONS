class Solutionn {
public:

    typedef pair<int,int> p;

    int getManhattenDistance(int x1, int y1, int x2, int y2){

        return abs(x2-x1) + abs(y2-y1); 
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        int minCostToConnectAll = 0;

        unordered_map<int,vector<vector<int>>> adj;

        for(int i=0; i<n; i++){

            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j=0; j<n; j++){

                if(i != j){

                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int manhattenDistance = getManhattenDistance(x1,y1,x2,y2);

                    adj[i].push_back({j,manhattenDistance});
                    adj[j].push_back({i,manhattenDistance});
                }
            }
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0,0});

        vector<int> vis(n,0);

        while(!pq.empty()){

            int currentDistance = pq.top().first;
            int currentNode = pq.top().second;

            pq.pop();

            if(vis[currentNode]) continue;
            
            vis[currentNode] = 1;
            minCostToConnectAll += currentDistance;

            for(auto x : adj[currentNode]){

                int adjacentNode = x[0];
                int distance = x[1];

                if(!vis[adjacentNode]){

                    pq.push({distance, adjacentNode});
                }
            }
        }

        return minCostToConnectAll;
    }
};


class Solution {
public:

    typedef pair<int,int> p;

    int getManhattenDistance(int x1, int y1, int x2, int y2){

        return abs(x2-x1) + abs(y2-y1); 
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // OPTIMAL APPRAOCH

        int n = points.size();
        vector<int> distance(n,1e9);
        distance[0] = 0;
        int sum = 0;
        vector<int> vis(n,0);
        
        priority_queue<p,vector<p>, greater<p>> pq;
        pq.push({0,0});

        while(!pq.empty()){

            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = 1;

            sum += currentDistance;

            for(int v=0; v<n; v++){

                if(!vis[v]){

                    int newDistance = getManhattenDistance(points[v][0], points[v][1], points[u][0], points[u][1]);

                    if(newDistance < distance[v]){

                        distance[v] = newDistance;
                        pq.push({newDistance,v});
                    }
                }
            }
        }

        return sum;
        
    }
};