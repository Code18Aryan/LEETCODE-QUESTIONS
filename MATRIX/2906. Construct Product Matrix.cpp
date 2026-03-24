class Solution {
public:

    typedef long long ll;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m,1));
        ll left = grid[0][0];
        ll right = grid[n-1][m-1];
        int mod = 12345;

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(i == 0 && j == 0) continue;

                ans[i][j] = left % mod;
                left = (left * (grid[i][j] % mod)) % mod;
                
            }
        }

        for(int i=n-1; i>=0; i--){

            for(int j=m-1; j>=0; j--){

                if(i == n-1 && j == m-1) continue;

                ans[i][j] = (ans[i][j] * right) % mod;
                right = (right * (grid[i][j] % mod)) % mod;
            }
        }

        return ans;
    }
};