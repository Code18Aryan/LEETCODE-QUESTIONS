class Solution {
  public:
    
    void generateAllString(int index, int cnt, string num, string ip, string &str, vector<string>&ans){
        
        if(cnt > 4) return;
        
        if(index >= str.size()){
            
            if(cnt == 4 && num == ""){
                
                ip.pop_back();
                ans.push_back(ip);
            }
            
            return;
        }
        
        num += str[index];
        
        if(num.size() > 1 && num[0] == '0') return;
        
        int number = stoi(num);
        
        if(number <= 255){
            
            generateAllString(index+1,cnt,num,ip,str,ans);
            generateAllString(index+1,cnt+1,"",ip+num+".",str,ans);
        }
        
    }
    
  
    vector<string> generateIp(string &s) {
        
        vector<string> ans;
        int n = s.size();
        
        if(n < 4 || n > 12) return ans;
        
        generateAllString(0,0,"","",s,ans);
        
        return ans;
        
    }
};