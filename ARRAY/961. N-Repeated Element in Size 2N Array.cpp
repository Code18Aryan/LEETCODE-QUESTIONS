class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int targetSize = nums.size()/2;

        for(auto &x : nums){

            mpp[x]++;
            
            if(mpp[x] == targetSize){

                return x;
            }
        }

        return -1;
    }
};