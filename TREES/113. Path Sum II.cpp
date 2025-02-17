problem link - https://leetcode.com/problems/path-sum-ii/description
/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void hasPath(TreeNode* root, int sum, int target, vector<int>nums, vector<vector<int>>&ans){

        if(!root) return;

        sum += root -> val;
        nums.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL){

            if(sum == target){

                ans.push_back(nums);
            }

            return;
        }

        hasPath(root -> left, sum, target, nums,ans);
        hasPath(root -> right, sum, target, nums,ans);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> nums;

        if(!root) return ans;

        hasPath(root,0,targetSum,nums,ans);

        return ans;
        
    }
};