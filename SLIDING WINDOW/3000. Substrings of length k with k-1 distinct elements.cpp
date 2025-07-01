class Solution {
  public:
    int substrCount(string &s, int k) {
        
        int n = s.size();
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<char,int> mpp;
        
        while( j < n){
            
            mpp[s[j]]++;
            
            if(j-i+1 == k){
                
                if(mpp.size() == k-1){
                    
                    count++;
                }
                
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            
            j++;
        }
        
        return count;
    }
};