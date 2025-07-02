class Solution {
  public:
    int totalElements(vector<int> &arr) {
        
        int n = arr.size();
        int i = 0;
        int j = 0;
        int maxSize = 0;
        unordered_map<int,int> mpp;
        
        
        while(j < n){
            
            mpp[arr[j]]++;
            
            while(mpp.size() > 2){
                
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0) mpp.erase(arr[i]);
                i++;
            }
            
                maxSize = max(maxSize, j-i+1);
            
            
            j++;
        }
        
        return maxSize;
    }
};