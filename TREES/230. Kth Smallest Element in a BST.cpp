/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void exploreTree(Node* root, int k, priority_queue<int>&pq){
        
        if(!root) return;
        
        exploreTree(root -> left, k, pq);
        pq.push(root -> data);
        if(pq.size() > k) pq.pop();
        
        exploreTree(root -> right,k,pq);
    }
  
    int kthSmallest(Node *root, int k) {
        
        priority_queue<int> pq;
        
        exploreTree(root,k,pq);
        
        if(pq.size() < k) return -1;
        
        return pq.top();
        
    }
};