Question Link - https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-10-03

class Solution {
public:

    typedef pair<int,pair<int,int>> p;

    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        priority_queue<p,vector<p>,greater<p>> pq;
        int waterCapacity = 0;
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};

        for(int i=0; i<m; i++){

            pq.push({heightMap[0][i],{0,i}});
            vis[0][i] = 1;
            pq.push({heightMap[n-1][i],{n-1,i}});
            vis[n-1][i] = 1;
        }

        for(int i=1; i<n-1; i++){

            pq.push({heightMap[i][0],{i,0}});
            vis[i][0] = 1;
            pq.push({heightMap[i][m-1],{i,m-1}});
            vis[i][m-1] = 1;
        }

        while(!pq.empty()){

            auto x = pq.top();
            pq.pop();

            int currentHeight = x.first;
            int row = x.second.first;
            int col = x.second.second;

            for(int i=0; i<4; i++){

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc]){

                    waterCapacity += max((currentHeight - heightMap[nr][nc]),0);

                    vis[nr][nc] = 1;
                    pq.push({max(currentHeight,heightMap[nr][nc]),{nr,nc}});
                }

            }
        }

        return waterCapacity;
    }

};
