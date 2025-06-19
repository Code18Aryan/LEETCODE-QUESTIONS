class Solution {
  public:
    string caseSort(string& s) {
       
       vector<char> lower,upper;
       
       for(auto x : s){
           
           if(isupper(x)){
               
               upper.push_back(x);
           }
           
           else if(islower(x)){
               
               lower.push_back(x);
           }
       }
       
       sort(lower.begin(),lower.end());
       sort(upper.begin(),upper.end());
       
       string ans = "";
       
       int left = 0;
       int right = 0;
       
       for(int i=0; i<s.size(); i++){
           
           if(isupper(s[i])){
               
               ans += upper[left];
               left++;
               
           }
           
           else if(islower(s[i])){
               
               ans += lower[right];
               right++;
           }
       }
       
       return ans;
    }
};