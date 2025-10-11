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

    typedef pair<int,ListNode*> p;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n == 0) return {};
        if(n == 1) return lists[0];

        priority_queue<p,vector<p>,greater<p>> pq;
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        for(int i=0; i<n; i++){

            if(lists[i] != NULL){

                pq.push({lists[i] -> val, lists[i]});
            }
        }

        while(!pq.empty()){

            auto x = pq.top();
            pq.pop();

            temp -> next = x.second;
            temp = temp -> next;

            if(x.second -> next) pq.push({x.second -> next -> val, x.second -> next});
        }

        return newHead -> next;
    }
};