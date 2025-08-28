Question - https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> diagonal;

        for(int i=0; i<n; i++){

            diagonal.push_back(grid[i][i]);
        }

        sort(diagonal.begin(),diagonal.end(), greater<>());

        
        for(int i=0; i<n; i++){

            grid[i][i] = diagonal[i];
        }

        for(int i=1; i<n; i++){

            vector<int> bottomLeft,topRight;

            for(int j=0; j<(n-i); j++){

                bottomLeft.push_back(grid[i+j][j]);
                topRight.push_back(grid[j][i+j]);
            }

            sort(bottomLeft.begin(),bottomLeft.end(), greater<>());
            sort(topRight.begin(),topRight.end());

            for(int j=0; j<(n-i); j++){

                grid[i+j][j] = bottomLeft[j];
                grid[j][i+j] = topRight[j];
            }

        }

        return grid;
    }
};