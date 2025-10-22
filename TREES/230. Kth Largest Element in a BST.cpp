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

// Question Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
class Solution {
public:

    void findElement(TreeNode* root, int &n, int k, int &ans){

        if(!root || ans != -1) return;

        findElement(root -> left, n, k,ans);
        n++;

        if(n == k) ans = root -> val;

        findElement(root -> right,n,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        if(!root) return -1;

        int ans = -1;
        int n = 0;

        findElement(root,n,k,ans);

        return ans;
    }

};
