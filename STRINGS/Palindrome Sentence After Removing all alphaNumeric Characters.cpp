class Solution {
  public:
    
    bool isPalindrome(string str){
        
        int low = 0;
        int high = str.size() -1;
        
        
        while( low < high){
            
            if(str[low] != str[high]) return false;
            low++;
            high--;
        }
        
        return true;
        
        
    }
  
    bool isPalinSent(string &s) {
        
        string str = "";
        
        // isalnum(s[i]) 
        
        for(int i=0; i<s.size(); i++){
        
            
            if( (s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 &&s[i] <= 122)){
                
                if(isupper(s[i])){
                    
                    str += tolower(s[i]);
                    
                }
                
                else str += s[i];
            }
        }
        
        
        
        return isPalindrome(str);
    }
};