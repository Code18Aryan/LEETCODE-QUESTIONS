class Solution {
public:

    typedef pair<int,pair<int,int>> p;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        distance[0][0] = 0;

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return dist;

            for(int i=0; i<4; i++){

                int nr = dr[i] + row;
                int nc = dc[i] + col;

                if(nr < n && nr >= 0 && nc < m && nc >= 0){

                    int req = max(moveTime[nr][nc] - dist,0);
                    int currTime = dist + req+ 1;
                    
                    if(currTime < distance[nr][nc]){

                        distance[nr][nc] = currTime;
                        pq.push({distance[nr][nc], {nr,nc}});
                    }
                }
            }
        }

        return distance[n-1][m-1];
    }
};