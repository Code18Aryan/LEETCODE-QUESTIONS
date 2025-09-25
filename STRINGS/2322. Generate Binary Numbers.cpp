class Solution {
  public:
    
    string toBinary(int n) {
        
    if (n == 0) return "0";  

    string binary = "";
    
    while (n > 0) {
        
        binary += (n % 2 == 0 ? '0' : '1');
        
        n /= 2;
    }

        reverse(binary.begin(), binary.end());  
    
         return binary;
    }
  
    vector<string> generateBinary(int n) {
        
        vector<string> ans;
        
        for(int i=1; i<=n; i++){
            
            ans.push_back(toBinary(i));
        }
        
        return ans;
        
    }
};