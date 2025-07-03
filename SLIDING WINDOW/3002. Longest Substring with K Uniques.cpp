class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int i = 0, j = 0, maxLength = 0;
        unordered_map<char,int> mpp;
        
        while(j < n){
            
            mpp[s[j]]++;
            
            while(mpp.size() > k){
                
                mpp[s[i]]--;
                
                if(mpp[s[i]] == 0){
                    
                    mpp.erase(s[i]);
                }
                
                i++;
            }
            
            if(mpp.size() == k){
                
                maxLength = max(maxLength,j-i+1);
                
            }
            
            j++;
        }
        
        return maxLength == 0 ? -1 : maxLength;
    }
};