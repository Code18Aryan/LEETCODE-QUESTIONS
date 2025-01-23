class Solution {
public:

    bool isValid(int row, int col , int m ,int n){
         
          if(row < m && row >= 0 && col < n && col >= 0) return true;

          return false;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis = ans;

        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(isWater[i][j] == 1){

                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }


        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};

        while(!q.empty()){

            auto x = q.front();
            q.pop();

            int dist = x.first;
            int row = x.second.first;
            int col = x.second.second;

            ans[row][col] = dist;

            for(int i=0; i<4; i++){
                 
                 int nRow = changeRow[i] + row;
                 int nCol = changeCol[i] + col;

                 if(isValid(nRow,nCol,m,n) && !vis[nRow][nCol]){
                     
                      vis[nRow][nCol] = 1;
                      q.push({dist + 1, {nRow,nCol}});
                 }
            }
        }

        return ans;
        
    }
};