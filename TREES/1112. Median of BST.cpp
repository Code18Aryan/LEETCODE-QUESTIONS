/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

// GFG Question Link - https://www.geeksforgeeks.org/problems/median-of-bst/1

class Solution {
  public:
    
    void getElement(Node* root, vector<int>&nodes){
        
        if(!root){
            
            return;
        }
        
        getElement(root -> left,nodes);
        
        nodes.push_back(root -> data);
        
        getElement(root -> right,nodes);
    }
  
  
    int findMedian(Node* root) {
        
        vector<int> nodes;
        
        getElement(root,nodes);
        
        return nodes.size() % 2 == 0 ? nodes[(nodes.size() / 2 )- 1] : nodes[nodes.size()/2];
        
    }
};
