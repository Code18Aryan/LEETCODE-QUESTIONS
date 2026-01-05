class Solution {
public:

    typedef long long ll;

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        ll sum = 0;
        int negativeCnt = 0;
        int minNumber = 1e9;

        for(int i=0; i<matrix.size(); i++){

            for(int j=0; j<matrix[0].size(); j++){

                sum += abs(matrix[i][j]);
                minNumber = min(minNumber,abs(matrix[i][j]));
                if(matrix[i][j] < 0) negativeCnt ++;
            }
        }

        if(negativeCnt & 1){

            sum = sum - (2 * minNumber);
        }

        return sum;
    }
};