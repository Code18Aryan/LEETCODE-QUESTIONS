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

    int findDistance(TreeNode* root){

        if(!root) return 0;
        int left = findDistance(root -> left);
        int right = findDistance(root -> right);

        return 1 + max(left,right);
    }


    bool isBalanced(TreeNode* root) {
        
        if(!root) return true;

        int leftHeight = findDistance(root -> left);
        int rightHeight = findDistance(root -> right);

        bool left  = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(abs(leftHeight - rightHeight) > 1) return false;

        return left && right;
    }
};