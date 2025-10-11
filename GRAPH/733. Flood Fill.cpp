class Solution {
public:

    vector<int> dr = {-1,0,+1,0};
    vector<int> dc = {0,+1,0,-1};

    void solve(int row, int col,int n, int m, int oldColor, int newColor, vector<vector<int>>&image
    ,vector<vector<int>>&ans){

        ans[row][col] = newColor;

        for(int i=0; i<4; i++){

            int nRow = row + dr[i];
            int nCol = col + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == oldColor &&
             ans[nRow][nCol] != newColor){

                solve(nRow,nCol,n,m,oldColor,newColor,image,ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        int newColor = color;

        //solve(sr,sc,n,m,oldColor,newColor,image,ans);

        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc] = newColor;

        while(!q.empty()){

            auto x = q.front();
            q.pop();

            int row = x.first;
            int col = x.second;

            for(int i=0; i<4; i++){

                int nRow = row + dr[i];
                int nCol = col + dc[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == oldColor &&
                ans[nRow][nCol] != newColor){

                    ans[nRow][nCol] = newColor;
                    q.push({nRow,nCol});
                }

              
            }
        }

        return ans;

    }
};