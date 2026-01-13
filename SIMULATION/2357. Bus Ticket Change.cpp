
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        vector<int> ans;
        
        int i=0;
        int j = 0;
        
        int n = arr.size();
        
        map<int,int> mpp;
        
        while( j < n){
            
            mpp[arr[j]]++;
            
            if(j-i+1 == k){
                
                ans.push_back(mpp.rbegin() -> first);
                mpp[arr[i]]--;
                
                if(mpp[arr[i]] == 0){
                    
                    mpp.erase(arr[i]);
                }
                
                i++;
            }
            
            j++;
        }
        
        return ans;
        
    }
};

