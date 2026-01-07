class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        
        int n = arr.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        int i=0, j=0;
        
        while(j < n){
            
            mpp[arr[j]]++;
            
            if((j-i+1) == k){
                
                ans.push_back(mpp.size());
                
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