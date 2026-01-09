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

    TreeNode* foundAncestor(TreeNode* root, int p, int q){

        if(root == NULL || root -> val == p || root -> val == q) return root;

        TreeNode* left = foundAncestor(root -> left, p,q);
        TreeNode* right = foundAncestor(root -> right,p,q);

        if(!left) return right;
        if(!right) return left;

        return root; 
    }

    pair<TreeNode*,int> dfs(TreeNode* root){

        if(!root) return {root,0};

        pair<TreeNode*,int>  leftDepth= dfs(root -> left);
        pair<TreeNode*,int>  rightDepth = dfs(root -> right);

        if(leftDepth.second == rightDepth.second){

            return {root,leftDepth.second+1};
        }

        if(leftDepth.second > rightDepth.second){

            return {leftDepth.first,leftDepth.second+1};
        }

        return {rightDepth.first, rightDepth.second+1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        if(!root) return root;

       /* queue<TreeNode*> q;
        q.push(root);

        vector<int> leafNodes;

        while(!q.empty()){

            int size = q.size();

            leafNodes.clear();

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                leafNodes.push_back(node -> val);

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
        }

        TreeNode* ans = new TreeNode(leafNodes[0]);

        for(int i=0; i<leafNodes.size(); i++){

            ans = foundAncestor(root,ans -> val, leafNodes[i]);

            cout<<ans -> val<<endl;
        }

        return ans;  */

        return dfs(root).first;
    }
};