/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void exploreTree(TreeNode* root, unordered_map<int,TreeNode*> &mpp){

        if(!root) return;

        if(root -> left) mpp[root -> left -> val] = root;

        exploreTree(root -> left,mpp);

        if(root -> right) mpp[root -> right -> val] = root;

        exploreTree(root -> right,mpp);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        if(!root ) return ans;
        if(k == 0) return {target -> val};
        
        unordered_map<int,TreeNode*> mpp; // key is int because all are unique but if interviwer says it has duplicate then store both as TreeNode*
        exploreTree(root,mpp);

        for(auto x : mpp){

            cout<<x.first<<" "<<x.second -> val;
            cout<<endl;
        }

        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target] = 1;
        int level = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                vis[node] = 1;

                if(node -> left && !vis[node -> left]) q.push(node -> left);
                if(node -> right && !vis[node -> right]) q.push(node -> right);
                if(mpp.find(node -> val) != mpp.end() && !vis[mpp[node -> val]]) q.push(mpp[node -> val]);
            }

            if(!q.empty()) level++;

            if(level == k) break;
        }

        while(!q.empty()){

            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;
    }
};