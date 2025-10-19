/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    int bs(vector<int>&nums, int target){
        
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] >= target){
                
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return ans;
        
    }
  
    
    void getElement(Node* root, vector<int>&nodes){
        
        if(!root) return;
        
        getElement(root -> left, nodes);
        nodes.push_back(root -> data);
        getElement(root -> right, nodes);
    }
    
    typedef pair<int,int> p;
  
    vector<int> getKClosest(Node* root, int target, int k) {
        
        vector<int> nodes;
        priority_queue<p> pq;
        vector<int> ans;
        
        getElement(root,nodes);
        
        
        for(int i=0; i<nodes.size(); i++){
            
            pq.push({abs(nodes[i]-target),nodes[i]});
            
            if(pq.size() > k) pq.pop();
        }
        
        while(!pq.empty() && k--){
            
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        
        return ans;
        
    }
};