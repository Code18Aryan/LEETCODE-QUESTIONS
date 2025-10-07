/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // Dummy Node Approach 
        
        if(head == NULL || head -> next == NULL) return head;

        ListNode* oddStart = new ListNode(-1);
        ListNode* evenStart = new ListNode(-1);
        ListNode* odd = oddStart;
        ListNode* even = evenStart;
        int length = 1;

        while(head){

            if(length & 1){

                odd -> next = head;
                odd = odd -> next;
            }

            else{

                even -> next = head;
                even = even -> next;
            }
            
            length++;
            head = head -> next;
        }

        even -> next = nullptr;
        
        if(oddStart -> next == nullptr) return evenStart ->next;

        odd -> next = evenStart -> next;
        return oddStart -> next;
        
        
        // Inplace 
        
         ListNode* oddEvenList(ListNode* head) {
             
         if (head == NULL || head->next == NULL) return head;

         ListNode* oddNode = head;
         ListNode* evenNode = head->next;
         ListNode* evenStart = head->next;
         
         // if length is even the evenNode will be last to null
         //eles evenNode is odd willbe null
    
         while (evenNode != NULL && evenNode->next != NULL){
             
            oddNode->next = oddNode->next->next;
            evenNode->next = evenNode->next->next;

            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

         oddNode->next = evenStart;
         return head;
         
        }

    }
};




