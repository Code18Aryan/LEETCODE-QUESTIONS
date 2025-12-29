class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        //using priority queue
       /* priority_queue<int> pq;
        
        for(auto &x : a){
            
            pq.push(x); if(pq.size() > k) pq.pop();
        }
        
        for(auto &x : b){
            
            pq.push(x); if(pq.size() > k) pq.pop();
        }
        
        return pq.top();  */
        
        // using sorting 
        
        /* int left = a.size()-1;
        int right = 0;
        
        while(left >= 0 && right < b.size()){
            
            if(a[left] >= b[right]){
                
                swap(a[left],b[right]);
                left--;
                right++;
            }
            
            else break;
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return (k > a.size()) ? b[k-a.size()-1] : a[k-1]; */
        
        // 3rd Approach using binary search beacuse the given array is sorted so we can think of bs
        
        int low = min(a[0],b[0]);
        int high = max(a[a.size()-1],b[b.size()-1]);
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            int x = upper_bound(a.begin(),a.end(),mid) - a.begin();
            int y = upper_bound(b.begin(),b.end(),mid) - b.begin();
            
            if(x + y < k) low = mid+1;
            else high = mid-1;
        }
        
        return low;
        
    }
};