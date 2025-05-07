class Solution {
  public:
  
    bool isLeaf(Node* root){
        
        if(!root -> left && !root -> right) return true;
        
        return false;
    }
    
    void getPath(Node* root, vector<vector<int>>&ans, vector<int>&nums){
        
        if(!root){
            
            return;
        }
        
        nums.push_back(root -> data);
        
        if(isLeaf(root)){
            
            ans.push_back(nums);
        }
        
        getPath(root -> left, ans,nums);
        getPath(root -> right,ans,nums);
        
        nums.pop_back();
    }
  
  
    vector<vector<int>> Paths(Node* root) {
        
        if(!root) return {{root -> data}};
        
        vector<vector<int>> ans;
        vector<int> nums;
        
        getPath(root,ans,nums);
        
        return ans;
    }
};
