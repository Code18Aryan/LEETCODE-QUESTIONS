class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();
        vector<int> suffixSum(nums.size(),0);
        suffixSum[n-1] = nums[n-1];

        int cnt = 0;

        for(int i=n-2; i>=0; i--){

            suffixSum[i] = suffixSum[i+1] + nums[i];
        }

        int prefixSum = 0;

        for(int i=0; i<n-1; i++){

            prefixSum += nums[i];

            if(abs(prefixSum - suffixSum[i+1]) % 2 == 0) cnt++;
        }

        return cnt;
    }
};