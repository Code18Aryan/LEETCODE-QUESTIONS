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
class FindElements {
public:

    unordered_set<int>st;

    FindElements(TreeNode* root) {
        
        root -> val = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* node = q.front();
                q.pop();
                st.insert(node -> val);

                if(node -> left != NULL){

                    node -> left -> val = 2 *node -> val + 1;
                    q.push(node -> left);
                }

                if(node -> right != NULL){

                    node -> right -> val = 2 *node -> val + 2;
                    q.push(node -> right);
                }   
            }
        }

    }
    
    bool find(int target) {

        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */