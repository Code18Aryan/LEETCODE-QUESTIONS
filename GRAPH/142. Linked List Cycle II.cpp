/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL)  return NULL; 

        ListNode* start = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while( fast -> next != NULL && fast -> next -> next != NULL){
             
             slow = slow -> next;
             fast = fast -> next -> next;

             if(fast == slow){
                  
                  while(start != slow){
                       
                        start = start -> next;
                        slow = slow -> next;
                  }

                  return start;
             }
        } 

        return NULL;
        
    }
};



/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/


class Solution {
  public:
    Node* findFirstNode(Node* head) {
        
        if(head == NULL || head -> next == NULL) return NULL;
        
        Node* temp = head;
        
        unordered_set<Node*> st;
        
        while(temp != NULL){
            
            if(st.find(temp) != st.end()) return temp;
            
            st.insert(temp);
            
            temp = temp -> next;
        }
        
        return NULL;
    }
};