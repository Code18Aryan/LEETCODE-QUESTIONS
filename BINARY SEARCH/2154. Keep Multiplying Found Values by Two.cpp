// Ques Link = https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        sort(nums.begin(),nums.end());

        while(true){

            int index = lower_bound(nums.begin(),nums.end(),original) - nums.begin();

            if(index >= nums.size() || index < 0 || nums[index] != original)  break;

            original *= 2;

        }

        return original;
    }

};
