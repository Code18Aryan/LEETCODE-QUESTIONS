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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(head == NULL) return {-1,-1};

        ListNode* temp = head;
        vector<int> nodes;
        vector<int> indices;

        while(temp){

            nodes.push_back(temp -> val);
            temp = temp -> next;
        }

        for(int i=1; i<nodes.size()-1; i++){

            if((nodes[i-1] > nodes[i] && nodes[i] < nodes[i+1]) || (nodes[i-1] < nodes[i] && nodes[i] > nodes[i+1])) indices.push_back(i);
        }

        if(indices.empty() || indices.size() == 1) return {-1,-1};

        int localMinima = INT_MAX;
        int localMaxima = indices[indices.size()-1] - indices[0];

        for(int i=0; i<indices.size()-1; i++){

            int diff = indices[i+1] - indices[i];

            if(diff < localMinima) localMinima = diff;
        }

        return {localMinima, localMaxima};

    }
};