class Solution {
public:

    int findNearesrRequiredRow(int row, int n, vector<int>&endZeros){

        int requiredZeros = n-row-1;
        bool find = false;
        int i;

        for(i=row; i<n; i++){

            if(endZeros[i] >= requiredZeros){
                find = true;
                break;
            }
        }

        if(!find) return -1;

        for(int j=i; j>=row+1; j--){

            swap(endZeros[j],endZeros[j-1]);
        }

        return i;
    }


    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();    
        int minSteps = 0;

        vector<int> endZeros(n,0);

        for(int i=0; i<n; i++){

            int cntZeros = 0;

            for(int j=n-1; j>=0; j--){

                if(grid[i][j] != 0) break;
                cntZeros++;
            }

            endZeros[i] = cntZeros;
        }

        for(int i=0; i<n; i++){

            int nearestRequiredRow = findNearesrRequiredRow(i,n,endZeros);

            if(nearestRequiredRow == -1) return -1;

            minSteps += (nearestRequiredRow-i);
        }

        return minSteps;
    }
};