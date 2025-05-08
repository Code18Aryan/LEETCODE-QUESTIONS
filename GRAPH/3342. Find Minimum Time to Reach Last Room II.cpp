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

        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return dist;

            for(int i=0; i<4; i++){

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr < n && nr >=0 && nc < m && nc >= 0){

                    int wait = moveTime[nr][nc] - dist;
                    if(wait < 0) wait = 0;
                    int currTime = dist + wait;

                    if(row == 0 && col == 0) currTime += 1;
                    else if((row + col) % 2 == 1) currTime += 2;
                    else currTime += 1;

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