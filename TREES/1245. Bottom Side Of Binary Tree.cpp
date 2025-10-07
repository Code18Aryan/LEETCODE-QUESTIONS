/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        vector<int> ans;
        map<int,int> mpp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                mpp[level] = node -> data;
                
                if(node ->left) q.push({node -> left, level-1});
                if(node -> right) q.push({node -> right,level+1});
            }
        }
        
        for(auto &x : mpp){
            
            ans.push_back(x.second);
        }
        
        return ans;
    
    }
};