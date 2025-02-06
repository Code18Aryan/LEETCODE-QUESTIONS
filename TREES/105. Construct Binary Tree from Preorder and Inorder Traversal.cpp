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


    TreeNode* uniqueTree(vector<int>& preOrder, int preStart, int preEnd, 
                       
     vector<int> & inOrder, int inStart , int inEnd , map<int,int> &mpp){


         if( preStart > preEnd || inStart > inEnd) return NULL;
          
           TreeNode* root = new TreeNode( preOrder[preStart]);


           int inRoot = mpp[root -> val];
           int numsLeft = inRoot - inStart;

           root -> left = uniqueTree(preOrder,preStart + 1, preStart + numsLeft,
            
                     inOrder, inStart , inRoot -1 , mpp);

           root -> right = uniqueTree(preOrder, preStart + numsLeft + 1, preEnd,
            
                    inOrder, inRoot + 1 , inEnd , mpp);   


            return root;             


     }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preStart = 0;
        int inStart = 0;
        int preEnd = preorder.size() -1;
        int inEnd = inorder.size() -1;

        unordered_map<int,int> mpp;

        for(int i=0; i<inorder.size(); i++){
             
              mpp[inorder[i]] = i;
        }

        TreeNode* root = uniqueTree(preorder, preStart, preEnd, inorder, inStart, 
                                
                                inEnd, mpp);

          return root;                      
        
    }
};