LINK - https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int n = nums.size();

        if(n % 2 == 1) return false;

        unordered_map<int,int> mpp;
        int cnt = 0;

        for(int i=0; i<n; i++){

            if(mpp.find(nums[i]) != mpp.end()){

                cnt++;

                mpp[nums[i]]--;

                if(mpp[nums[i]] == 0){

                    mpp.erase(nums[i]);
                }
            }

            else mpp[nums[i]]++;
        }

        return n/2 == cnt;
    }
};