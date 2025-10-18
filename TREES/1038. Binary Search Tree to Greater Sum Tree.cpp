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

// QuesLink - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
class Solution {
public:

    void createGreaterBST(TreeNode*root, int &sum){

        if(!root) return;

        createGreaterBST(root -> right, sum);
        sum += root -> val;
        root -> val = sum;
        createGreaterBST(root -> left,sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root) return root;

        int sum = 0;

        createGreaterBST(root,sum);

        return root;
    }

};
