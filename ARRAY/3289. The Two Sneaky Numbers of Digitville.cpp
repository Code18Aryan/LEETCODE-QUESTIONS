// Ques Link - https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        vector<int> ans;
        
        for(auto &x : nums) mpp[x]++;

        for(auto &x : mpp){

            if(x.second == 2) ans.push_back(x.first);
        }

        return ans;

    }

};
