/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solutionn{
  public:
  
    Node* split(Node* head){
        
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            
            fast = fast -> next -> next;
            
            if(fast != NULL){
                
                slow = slow -> next;
            }
        }
        
        Node* ans = slow -> next;
        slow -> next = nullptr;
        
        return ans;
    }
    
    Node* merge(Node* first , Node* second){
        
        if(!first) return second;
        if(!second) return first;
        
        if(first -> data < second -> data){
            
            first -> next = merge(first -> next , second);
            return first;
        }
        
        else{
            
            second -> next = merge(first,second -> next);
            
            return second;
        }
    }
  
  
  
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        Node* second = split(head);
        
        head = mergeSort(head);
        second = mergeSort(second);
        
        return merge(head,second);
    }
};






class A{
    
    public:
    
    vector<int> getElement(Node* &head){
        
        vector<int> nums;
        Node* temp = head;
        
        while(temp){
            
            nums.push_back(temp -> data);
            temp = temp -> next;
        }
        
        return nums;
        
    }
    
    Node* getLinkedList(vector<int>&nums){
        
        Node* newHead = new Node(-1);
        Node* connect = newHead;
        
        for(auto x : nums){
            
            connect -> next = new Node(x);
            connect = connect -> next;
        }
        
        return newHead -> next;
    }
    
    void merge(vector<int>&nums, int low , int mid, int high){
        
        vector<int> ans;
        int left = low;
        int right = mid+1;
        
        while(left <= mid && right <= high){
            
            if(nums[left] <= nums[right]){
                
                ans.push_back(nums[left]);
                left++;
            }
            
            else{
                
                ans.push_back(nums[right]);
                right++;
            }
        }
        
        while(left <= mid){
            
            ans.push_back(nums[left]);
            left++;
        }
        
        while(right <= high){
            
            ans.push_back(nums[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++){
            
            nums[i] = ans[i-low];
        }
    }
    
    void mergeSort(vector<int>&nums,int low, int high){
        
        if(low >= high) return;
        
        int mid = low + (high-low)/2;
        
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    
};


class Solution {
    
  public:
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head -> next == NULL) return head;
        
        A gfg;
        
        vector<int> nums = gfg.getElement(head);
        
        gfg.mergeSort(nums,0,nums.size()-1);
        
        Node* newHead = gfg.getLinkedList(nums);
        
        return newHead;
        
    }
};