/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
  
    Node* createList(vector<int>nums){
        
        Node* node = new Node(nums[0]);
        Node* head = node;
        
        for(int i=1; i<nums.size(); i++){
            
            node -> next = new Node(nums[i]);
            node = node -> next;
            
        }
        
        node -> next = head;
        
        return head;
    }
  
    Node* sortedInsert(Node* head, int data) {
        
        if(head == NULL){
            
            Node* node = new Node(data);
            
            node -> next = node;
            
            return node;
        }
        
        // if(data <= head -> data){
            
        //     Node* node = new Node(data);
            
        //     Node* curr = head;
            
        //     while(curr -> next != head){
                
        //         curr = curr -> next;
        //     }
            
        //     curr -> next = node;
        //     node -> next = head;
        //     head = node;
            
        //     return head;
        // }
        
        vector<int> nums;
        nums.push_back(head -> data);
        
        Node* temp = head -> next;
        //nums.push_back(data);
        
        while(temp != head){
            
            nums.push_back(temp -> data);
            temp = temp -> next;
        }
        
        //sort(nums.begin(),nums.end());
        
        
        int lowerBound = lower_bound(nums.begin(),nums.end(),data) - nums.begin();
        
        temp = head;
        
        nums.insert(nums.begin() + lowerBound,data);

        
        Node* newHead = createList(nums);
    
        
        return newHead;
    }
};