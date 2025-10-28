class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixSum(n+1);
        int cnt = 0;
        partial_sum(nums.begin(),nums.end(),prefixSum.begin() + 1);
        
        for(int i=0; i<n; i++){

            if(nums[i] == 0){

                if(prefixSum.back() == (2 * prefixSum[i])){

                    cnt += 2;
                }

                else if(abs(prefixSum.back() - (2 * prefixSum[i]))  == 1){

                    cnt += 1;
                }
            }
        }

        return cnt;
    }
};