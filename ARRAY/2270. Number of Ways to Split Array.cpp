class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();

        // Appraoch 1 using prefixSum vector and for each i prefix[i] >= (totalSum - sum till i) 

       /* vector<int> prefixSum(n,0);

        long long  totalSum = 0;

        int cnt = 0;

        for(int i=0; i<n; i++){
             
              totalSum += nums[i];

              prefixSum[i] = totalSum;
        }

        for(int i=0; i<n-1; i++){
             
             if(prefixSum[i] >= (totalSum - prefixSum[i])) cnt++;
        }

        return cnt;                             
        
            TC - O(n) for sum + O(n) for calculation total O(2n);
            SC - O(n) for vector prefixSum
        
        */

        // Appraoch we can remove space using sameapprcoh


        long long totalSum = 0;

        int cnt = 0;

        long long sum = 0;

        for(auto &x : nums){
             
             totalSum += x;
        }


        for(int i=0; i<n-1; i++){
             
             sum += nums[i];

             if(sum >= (totalSum - sum)) cnt++;
        }


        return cnt;
        
    }
};