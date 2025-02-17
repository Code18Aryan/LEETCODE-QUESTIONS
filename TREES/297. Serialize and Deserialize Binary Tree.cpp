/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        
        if(!root) return {};
        
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                Node* node = q.front();
                q.pop();
                
                if(node != NULL){
                    
                    q.push(node -> left);
                    q.push(node -> right);
                }
                
                if(node == NULL) ans.push_back(-1);
                else ans.push_back(node -> data);
            }
        }
        
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        
        if(arr.empty()) return NULL;
        
        int index = 0;
        
        Node* root = new Node(arr[index++]);
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                Node* node = q.front();
                q.pop();
                
                if(arr[index] == -1){
                    
                    node -> left = NULL;
                }
                
                else{
                    
                    Node* leftNode = new Node(arr[index]);
                    node -> left = leftNode;
                    q.push(leftNode);
                }
                
                index++;
                
                if(arr[index] == -1){
                    
                    node -> right = NULL;
                }
                
                else{
                    
                    Node* rightNode = new Node(arr[index]);
                    node -> right = rightNode;
                    q.push(rightNode);
                }
                
                index++;
            }
        }
        
        return root;
        
        
    }
};