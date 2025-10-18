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