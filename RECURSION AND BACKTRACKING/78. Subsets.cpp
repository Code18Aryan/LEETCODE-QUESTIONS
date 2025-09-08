class Solution {
public:	

    void helper(int index, vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp){

        if(index >= nums.size()){

            ans.push_back(temp);

            return;
        }

        temp.push_back(nums[index]);
        helper(index + 1, nums, ans, temp);
        
        temp.pop_back();
        helper(index + 1, nums,ans,temp);
    }

    vector<vector<int> > powerSet(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        helper(0,nums,ans,temp);

        return ans;
    }
};