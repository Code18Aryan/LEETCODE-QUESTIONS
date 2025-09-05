#include <bits/stdc++.h>
using namespace std;

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        Node* connectZero = zero;
        Node* connectOne = one;
        Node* connectTwo = two;
        Node* temp = head;
        
        while(temp){
            
            if(temp -> data == 0){
                
                connectZero -> next = temp;
                connectZero = connectZero -> next;
            }
            
            else if(temp -> data == 1){
                
                connectOne -> next = temp;
                connectOne = connectOne -> next;
            }
            
            else{
                
                connectTwo -> next = temp;
                connectTwo = connectTwo -> next;
            }
            
            temp = temp -> next;
        }
        
        connectZero -> next = (one -> next != NULL) ? one -> next : two -> next;
        connectOne -> next = two -> next;
        connectTwo -> next = nullptr;
        
        return zero -> next;
    }
};