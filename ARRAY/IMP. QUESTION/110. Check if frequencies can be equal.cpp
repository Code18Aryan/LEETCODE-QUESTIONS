class Solution {
  public:
    bool sameFreq(string& s) {
        
        if(s.size() == 1) return true;
        
        unordered_map<char,int> mpp;
        
        for(auto x : s){
            
            mpp[x]++;
        }
        
        for(int i=0; i<s.size(); i++){
            
            
            unordered_map<char,int> temp = mpp;
            
            char ch = s[i];
            
            temp[ch]--;
            
            if(temp[ch] == 0) temp.erase(ch);
            
            auto it = *temp.begin();
            int freq = it.second;
            
            bool check = true;
            
            for(auto x : temp){
                
                int currentFreq = x.second;
                
                if(freq != x.second){
                    
                    check = false;
                    break;
                    
                }
            }
            
            if(check) return true;

        }
        
        auto x = *mpp.begin();
        int frequency = x.second;
        
        for(auto x : mpp){
            
            if(x.second != frequency){
                
                return false;
            }
        }
        
        
        return true;
    }
};