problem link - https://leetcode.com/problems/path-sum/
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

// From Root to leaf Node

class Solution {
public:

    bool findPath(TreeNode* root, int sum, int target){

        if(!root) return false;

        sum += root -> val;

        if(root -> left == NULL && root -> right == NULL){

            if(sum == target){

                return true;
            }

            return false;
        }

        bool leftSide = findPath(root -> left , sum , target);
        bool rightSide = findPath(root -> right, sum, target);

        return leftSide || rightSide;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root) return false;

        return findPath(root,0,targetSum);
        
    }

};
