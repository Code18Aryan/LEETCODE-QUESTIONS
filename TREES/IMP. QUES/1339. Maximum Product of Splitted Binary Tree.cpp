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

    int mod = 1e9 + 7;
    typedef long long ll;

    int dfs(TreeNode* root, int totalSum,ll &ans){

        if(!root) return 0;

        int leftSum = dfs(root -> left, totalSum, ans);
        int rightSum = dfs(root -> right, totalSum,ans);

        int firstTreeSum = root -> val + leftSum + rightSum;
        int secondTreeSum = totalSum - firstTreeSum;

        ll product = (1LL * firstTreeSum * secondTreeSum);

        ans = max((ll)ans, product);
    
        return root -> val + leftSum + rightSum;
    }

    ll findSum(TreeNode* root){

        if(!root) return 0;

        ll leftSum = findSum(root -> left);
        ll rightSum = findSum(root -> right);

        return root -> val + leftSum + rightSum;
    }

    int maxProduct(TreeNode* root) {
        
        if(!root) return 0;

        ll totalSum = findSum(root);
        ll ans = 0;

        dfs(root,totalSum,ans);

        return ans % mod;
    }
};