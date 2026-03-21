class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        int steps = k;

        while(y < m && steps--){

            int i = x;
            int j = i+k-1;
        
            cout<<i<<" "<<j<<endl;

            while(i < n && j < n && i < j){

                swap(grid[i][y], grid[j][y]);
                i++;
                j--;
            }

            y++;
          
        }

        return grid;
    }
};