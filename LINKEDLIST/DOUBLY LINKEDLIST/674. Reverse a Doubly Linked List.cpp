/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
    
        Node* high = head;
        Node* low = head;
        int length = 1;
        
        while(high -> next != NULL){
            
            high = high -> next;
            length += 1;
        }
        
        length = length/2;
        
        while(length--){
            
            swap(low -> data, high -> data);
            
            low = low -> next;
            high = high -> prev;
        }
        
        return head;
        
        
    }
};