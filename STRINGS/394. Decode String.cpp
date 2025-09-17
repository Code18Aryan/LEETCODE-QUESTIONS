class Solution {
  public:
    string decodedString(string &s) {
        
        int n = s.size();
        stack<char> st;
        string ans = "";
        
        for(auto x : s){
        
            
            if(x == ']'){
                
                string currentWord = "";
                
                while(!st.empty() && st.top() != '['){
                    
                    currentWord += st.top();
                    st.pop();
                }
                
                st.pop();
                
                reverse(currentWord.begin(),currentWord.end());
                
                string temp = "";
            
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    
                    temp += st.top();
                    st.pop();
                }
                
                reverse(temp.begin(),temp.end());
                
                int times = 1;
                
                if(!temp.empty()){
                    
                    times = stoi(temp);
                }
                
                string word = "";
            
                while(times--){
                 
                     word += currentWord;
                 }
            
                for(auto it : word){
                
                    st.push(it);
                }
            }
            
            
            else st.push(x);
            
        }
        
        while(!st.empty()){
            
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};