class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_set<char> st(s.begin(),s.end());

        int cnt = 0;

        for(auto x : st){

            int start = -1;
            int end = -1;

            for(int i=0; i<s.size(); i++){
                 
                  if(s[i] == x){
                     
                      if(start == -1) start = i;

                      end = i;
                  }
            }

            unordered_set<char> st2;


            for(int index = start+1; index < end; index++){
                 
                 st2.insert(s[index]);
            }

            cnt += st2.size();
        }


        return cnt;
        
    }
};