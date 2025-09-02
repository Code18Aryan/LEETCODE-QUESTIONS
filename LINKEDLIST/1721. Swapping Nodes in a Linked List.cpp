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
    ListNode* swapNodes(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL || k == 0) return head;

        ListNode* first = head;
        ListNode* second = head;
        int length = 0;

        while(first){

            length += 1;
            first = first -> next;
        }

        if(k > length) return head;

        length = length - k;
        k = k-1;
        first = head;

        while(k--) first = first -> next;
        while(length--) second = second -> next;

        swap(first -> val , second -> val);

        return head;
        
        
    }
};