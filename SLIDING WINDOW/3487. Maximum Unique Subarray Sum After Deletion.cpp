class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        auto maxi = *max_element(nums.begin(),nums.end());

        if(maxi < 0) return maxi;

        unordered_map<int,int> mpp;

        for(auto x : nums){

            mpp[x]++;
        }

        int sum = 0;

        for(auto x : mpp){

            if(x.first >= 0){

                sum += x.first;
            }
        }

        return sum;
    }
};