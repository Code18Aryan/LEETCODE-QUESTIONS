class Solution {
  public:
    int minParentheses(string& s) {
       
       int n = s.size();
       stack<char> st;
       int cnt = 0;
       
       for(int i=0; i<n; i++){
           
           if(st.empty() && s[i] == ')') cnt++;
           
           else if(!st.empty() && s[i] == ')' && st.top() == '('){
               
               st.pop();
           }
           
           else st.push(s[i]);
       }
       
       cnt += st.size();
       
       return cnt;
        
    }
};