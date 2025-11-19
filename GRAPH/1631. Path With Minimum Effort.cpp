// Ques Link - https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
public:

    typedef pair<int,pair<int,int>> p;

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> distance(m, vector<int>(n,1e9));
        distance[0][0] = 0;

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});

        vector<int> x = {1,0,0,-1};
        vector<int> y = {0,-1,1,0};

        while(!pq.empty()){

            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            if(row == m-1 && col == n-1) return effort;

            pq.pop();

            for(int i=0; i<4; i++){

                int nRow = row + x[i];
                int nCol = col + y[i];

                if(nRow < m && nCol < n && nRow >= 0 && nCol >= 0){

                    int newEffort = max(effort, abs(heights[row][col]-heights[nRow][nCol]));

                    if(newEffort < distance[nRow][nCol]){

                        distance[nRow][nCol] = newEffort;

                        pq.push({newEffort, {nRow,nCol}});
                    }
                }
            }
        }

        return distance[m-1][n-1];
    }

};
