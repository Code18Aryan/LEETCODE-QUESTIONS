//Ques Link -https://leetcode.com/problems/binary-tree-maximum-path-sum/
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
    pair<int,int> solve(Node* root){
        
        if(root == NULL) return {0,0};
        
        pair<int,int> left = solve(root -> left);
        pair<int,int> right = solve(root -> right);
        
        if(left.first > right.first){
            
            return {left.first + 1 , root -> data + left.second};
        }
        else if(left.first < right.first){
            
            return {right.first + 1, root -> data + right.second};
        }
        else{
            
            if(left.second > right.second){
                
                return {left.first + 1, root -> data + left.second};
            }
            else{
                
                return {right.first +1 , root -> data + right.second};
            }
        }
    }
  
  
    int sumOfLongRootToLeafPath(Node *root) {
        
        pair<int,int> ans = solve(root);
        
        return ans.second;
    }
};
