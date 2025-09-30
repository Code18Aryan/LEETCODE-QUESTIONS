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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head -> next == NULL) return head;

        // Brute Force -> convert to vector then into linkedlist

        /* ListNode* temp = head;
        map<int,int> mpp;

        while(temp){

            mpp[temp -> val]++;

            temp = temp -> next;
        }

        ListNode* newHead = new ListNode(-1);
        temp = newHead;

        for(auto &x : mpp){

            if(x.second == 1){

                temp -> next = new ListNode(x.first);
                temp = temp -> next;
            }
        }

        temp -> next = NULL;

        return newHead -> next;   */


        // Optimal Using two pointer 

        ListNode* newHead = new ListNode(-1);
        ListNode* prev = newHead;
        ListNode* forward = head;
        prev -> next = head; // Because may be the first node has duplicates so a pointer to head

        // Prevoius pointer should only be moved if we find distint Element

        while(forward){

            if(forward -> next != NULL && forward -> val == forward -> next -> val){

                while(forward -> next != NULL && forward -> val == forward -> next -> val){

                    forward = forward -> next;
                }
                prev -> next = forward -> next;
            }
            else{
                prev -> next = forward;
                prev = prev -> next;
            }

            forward = forward -> next;
        }

        return newHead -> next;
    }
};