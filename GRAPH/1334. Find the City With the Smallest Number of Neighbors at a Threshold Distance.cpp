class Solution {
public:

    vector<int> findSmallestDistace(int n ,int node , vector<pair<int,int>> adj[]){

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node});

        vector<int> distance(n,1e9);
        distance[node] = 0;

        while(!pq.empty()){
             
              int dist = pq.top().first;
              int node = pq.top().second;

              pq.pop();

              for(auto adjNode : adj[node]){
                 
                   int v = adjNode.first;
                   int wt = adjNode.second;

                   if(dist + wt < distance[v]){
                     
                       distance[v] = dist + wt;

                       pq.push({distance[v],v});
                   }
              }
        } 

        return distance;
         
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {


        // vector<pair<int,int>> adj[n];

        // for(auto x : edges){
             
        //       int u = x[0];
        //       int v = x[1];
        //       int wt = x[2];

        //       adj[u].push_back({v,wt});
        //       adj[v].push_back({u,wt});
        // }

        // vector<int> neighbour(n);

        // for(int i=0; i<n; i++){

        //      int cnt = 0;

        //      vector<int> dist = findSmallestDistace(n,i,adj);

        //      for(int j=0; j<dist.size(); j++){
                 
        //           if(dist[j] <= distanceThreshold && dist[j] != 0) cnt++;
        //      }


        //     neighbour[i] = cnt;

        // }

        // priority_queue<pair<int,int>> pq;

        // for(int i=0; i<n; i++){
             
        //      pq.push({-neighbour[i],i});
        // }

        // return pq.top().second;


        // they said smallest city(2,3,4) reacheed return so min heap 2 at top
        // but return maxcity number
        // so max heap and  the city reached its still the same (-2,-3,-4) -2 at top
        // 

        vector<vector<int>> matrix(n, vector<int>(n,1e9));

        for(auto x : edges){

            int u = x[0];
            int v = x[1];
            int wt = x[2];

            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }

        for(int i=0; i<n; i++){

            matrix[i][i] = 0;
        }


        for(int k=0; k<n; k++){

            for(int i=0; i<n; i++){

                for(int j=0; j<n; j++){

                     matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int ansCity = -1;
        int ansCnt = n;

        for(int i=0; i<n; i++){

            int cnt = 0;

            for(int j=0; j<n; j++){

                if(matrix[i][j]  <= distanceThreshold){

                    cnt++;
                }
            }

            if(cnt <= ansCnt){

                ansCnt = cnt;
                ansCity = i;
            }
        }

        return ansCity;    
    }
};