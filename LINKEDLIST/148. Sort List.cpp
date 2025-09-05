#include <bits/stdc++.h>
using namespace std;


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
    ListNode* sortList(ListNode* head) {

        ListNode* temp = head;
        vector<int> ans;
        int cnt = 0;   int index = 0;

        while( temp != NULL){
             
              cnt++;
              ans.push_back(temp -> val);
              temp = temp -> next;
        }

        sort(ans.begin(),ans.end());

        temp = head;

        while( temp != NULL){
             
             temp -> val = ans[index];
             index++;
             temp = temp -> next;
        }

        return head;
        
    }
};