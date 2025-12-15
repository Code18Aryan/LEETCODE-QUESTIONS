class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();

        int totalEven = 0, totalOdd = 0;
        int leftEven = 0, leftOdd = 0;
        int cnt = 0;
        
        for (int i = 0; i < n; i++){
            
            if (i & 1) totalOdd += arr[i];
            else totalEven += arr[i];
        }

      
        for (int i = 0; i < n; i++){
            
            if (i & 1) totalOdd -= arr[i];
            else totalEven -= arr[i];

            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd + totalEven;

            if (newEven == newOdd) cnt++;

            if (i & 1) leftOdd += arr[i];
            
            else leftEven += arr[i];
        }

        return cnt;
    }
};
