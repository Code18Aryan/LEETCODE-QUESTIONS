#include <bits/stdc++.h>
using namespace std;

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        

        Node* fast = head;
        Node* slow = head;
        
        bool hasCycle = false;
        
        while(fast != NULL && fast -> next != NULL){
            
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(fast == slow){
                
                hasCycle = 1;
                break;
                
            }
        }
        
        if(hasCycle){
            
            Node* temp = slow -> next;
            int cnt = 1;
            
            while(temp != slow){
                
                cnt++;
                temp = temp -> next;
            }
            
            return cnt;
        }
        
        return 0;
        
        
    }
};