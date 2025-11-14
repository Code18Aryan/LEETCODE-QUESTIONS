class Solution {
public:

    void fillMatrix(int r1, int c1, int r2, int c2, vector<vector<int>> &grid){

        for(int i=r1; i<=r2; i++){

            for(int j=c1; j<=c2; j++){

                grid[i][j] += 1;
            }
        }
    }


    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> ans(n, vector<int>(n,0));

        for(auto &x : queries){

            int r1 = x[0];
            int c1 = x[1];
            int r2 = x[2];
            int c2 = x[3];

            fillMatrix(r1,c1,r2,c2,ans);
        }

        return ans;
    }
};