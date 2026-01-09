class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        
        int i = 0, j = 0, n = arr.size(), cnt = 0;
        
        /* Use Three loop and generate all subarray
        
        for(int i=0; i<n; i++){
            
            for(int j=i; j<n; j++){
                
                unordered_set<int> st;
                
                for(int k=i; k<=j; k++){
                    
                    if(st.size() > k) break; // Slight better because if in that subarry distinct element is > k then brea
                    
                    st.insert(arr[k]);
                
                }
                
                if(st.size() <= k) cnt++;
            }
        }  */
        
        /*
        
        for(int i=0; i<n; i++){
            
            unordered_set<int> st;
            
            for(int j=i; j<n; j++){
                
                //if(st.size() > k) break;
                
                st.insert(arr[j]);
            }
            
            if(st.size() <= k) cnt++;
        }
        
        */
        
        
        // Optimized two pointer solution
        
        unordered_map<int,int>mpp;
        
        while(j < n){
            
            mpp[arr[j]]++;
            
            while((mpp.size()) > k){
                
                mpp[arr[i]]--;
                
                if(mpp[arr[i]] == 0){
                    
                    mpp.erase(arr[i]);
                }
                
                i++;
            }
            
            cnt += (j-i+1);
            j++;
        }
    
        
        return cnt; 
    }
};