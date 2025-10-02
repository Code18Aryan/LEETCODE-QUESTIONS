 class A{
     
     public:
     
     void solve(int element,vector<vector<int>> &ans,vector<int>&nums, int sum, int k){
        
        if(sum < 0 || nums.size() > k) return;
        if(sum == 0 && nums.size() == k){
            
            ans.push_back(nums);
            return;
        }
        
        for(int i=element; i<=9; i++){
            
            nums.push_back(i);
            
            solve(i+1,ans,nums,sum-i,k);
            
            nums.pop_back();
        }
    }
     
     
 };


class Solution {
  public:
  
    vector<vector<int>> combinationSum(int n, int k) {
        
        if(n == 0 || k == 0) return {};
        
        vector<vector<int>> ans;
        vector<int> nums;
        
        A gfg;
        
        gfg.solve(1,ans,nums,n,k);
        
        return ans;
    }
};