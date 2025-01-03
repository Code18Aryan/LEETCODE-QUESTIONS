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

private:

   void getValues(TreeNode* root , int level , vector<int>&ans){
     
      if(!root) return;

      if(ans.size() == level){

         ans.push_back(root -> val);
      } 

      else{
         
         ans[level] = max(ans[level], root -> val);

      }

        getValues(root -> left, level + 1, ans);
        getValues(root -> right, level + 1, ans);

   }

public:
    vector<int> largestValues(TreeNode* root) {

        // vector<int> ans;
    
        // if( root == NULL) return ans;

        // queue<TreeNode*>q;
        // q.push(root);

        // while(!q.empty()){
             
        //       int size = q.size();
        //       int maxElement = INT_MIN;

        //       for(int i=0; i<size; i++){
                 
        //           TreeNode* node = q.front();
        //           q.pop();

        //           if( node -> left != NULL) q.push(node -> left);

        //           if( node -> right != NULL) q.push(node -> right);

        //           if( node -> val > maxElement) maxElement = node -> val;  
        //       }

        //       ans.push_back(maxElement);
        // }

        // return ans;

        //  DFS SOLUTION


        vector<int> ans;

        if(!root) return ans;

        getValues(root,0,ans);

        return ans;
        
    }
};