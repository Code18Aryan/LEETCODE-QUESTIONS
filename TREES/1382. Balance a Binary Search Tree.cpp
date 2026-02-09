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

    void inorder(TreeNode* root , vector<int>&nums){
         
         if( root == nullptr) return;


         inorder(root -> left , nums);
         nums.push_back(root ->val);
         inorder(root -> right ,nums);
    }


    TreeNode* createTree(vector<int>&nums ,int low , int high){
         
          if( low > high) return NULL;

          int mid = (low + high)/2;

          TreeNode* root = new TreeNode(nums[mid]);

          root -> left = createTree(nums , low , mid-1);

          root -> right = createTree(nums,mid+1,high);

          return root;
    }


    TreeNode* balanceBST(TreeNode* root) {

        vector<int>nums;

        inorder(root,nums);

        TreeNode* balancedBST = createTree(nums,0,nums.size()-1);

        return balancedBST;
        
    }
};