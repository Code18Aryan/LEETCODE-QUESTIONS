class Solution {
  public:
    int sumSubstrings(string &s) {
        
        /*
       
       int n = s.size();
       
       int totalSum = 0;
       
       for(int i=0; i<n; i++){
           
           string str = "";
           
           for(int j=i; j<n; j++){
               
               str += s[j];
               
               int sum = stoi(str);
               
               totalSum += sum;
           }
       }
       
       return totalSum;  */
       
       
       int n = s.size();
       
       int curr = 0;
       int prev = 0;
       int sum  = 0;
       
       for(int i=0; i<n; i++){
           
           curr = (prev * 10) + (s[i] - '0') * (i+1);
           prev = curr;
           sum += curr;
       }
       
       return sum;
    }
};