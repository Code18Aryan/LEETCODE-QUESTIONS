//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// Driver Code Ends
// FLYODD WARSHALL ALGO 

// BRUTE TO OPTIMAl APPROACH  PROBLEM

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
     
        unordered_map<int,vector<vector<int>>> adj;

        // prims algorithm
        // MST 
        
        int n = houses.size();
        
        for(int i=0; i<n-1; i++){
            
            for(int j=i+1; j<n; j++){
                
                int x1 = houses[i][0];
                int y1 = houses[i][1];
                int x2 = houses[j][0];
                int y2 = houses[j][1];
                
                int distance = abs(x2-x1) + abs(y2-y1);
                
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
            }
        }
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        
        int ans = 0;
        
        vector<int> vis(n,0);
        
        while(!pq.empty()){
            
            auto x = pq.top();
            pq.pop();
            
            int dist = x.first;
            int node = x.second.first;
            int parent = x.second.second;
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            
            ans += dist;
            
            for(auto x : adj[node]){
                
                int u = x[0];
                int wt = x[1];
                
                if(!vis[u]){
                    
                    pq.push({wt,{u,node}});
                }
            }
        }
        
        return ans;
     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends
