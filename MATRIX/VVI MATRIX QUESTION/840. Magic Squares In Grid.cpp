class Solution {

private:

    bool checkMagicSquare (int row , int col ,vector<vector<int>>& grid){

        unordered_set<int>st;

        for(int i=0; i<3; i++){
             
             for(int j=0; j<3; j++){
                 
                 int num = grid[i+row][j+col];

                 if( num < 1 || num > 9 || st.count(num)) return false;

                 else st.insert(num);
             }
        }

        int rowSum = grid[row][col] + grid[row][col+1] + grid[row][col+2];

        for(int i=0; i<3; i++){
             
             if(grid[i+row][col] + grid[i+row][col+1] +grid[i+row][col+2] != rowSum) return false;
        }

        for(int i=0; i<3; i++){
             
              if(grid[row][i+col] + grid[row+1][i+col] + grid[row+2][i+col] != rowSum) return false;
        }

        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != rowSum) return false;

        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != rowSum) return false;

        return true;
         
    }


public:

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(m < 3 || n < 3) return 0;

        int magicSquare = 0;

        for(int i=0; i<=m-3; i++){
             
              for(int j=0; j<=n-3; j++){

                   if(checkMagicSquare(i,j,grid)) magicSquare += 1;
              }
        }

        return magicSquare;
        
    }
};