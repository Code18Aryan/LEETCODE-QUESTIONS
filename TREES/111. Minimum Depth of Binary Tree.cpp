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

    int findMinPath(TreeNode* root){

        if(!root) return 0;

        int left = findMinPath(root -> left);
        int right = findMinPath(root -> right);

        if(left == 0) return 1 + right;
        if(right == 0) return 1 + left;

        return 1 + min(left,right);
    }


    int minDepth(TreeNode* root) {
        
       return  findMinPath(root);
       
    }
};