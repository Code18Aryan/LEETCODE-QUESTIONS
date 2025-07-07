class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        
        int first =  lower_bound(nums.begin().nums.end(),x) - nums.begin();
        int last = upper_bound(nums.begin(),nums.end(),x) - nums.begin();
        
        return {fast , last -1};
        
        
        vector<int> ans;

        int first = -1;
        int last = -1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] == target){

                if(first == -1) first = i;

                last = i;
            }
        }

        return {first,last};
    }
};