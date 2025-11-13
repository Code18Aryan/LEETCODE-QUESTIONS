class Solution {
public:
    int maxOperations(string s) {
        
        int i = 0, n = s.size(), cnt = 0, ones = 0;

        while(i < n){

            if(s[i] == '0'){

                cnt += ones;

                while(i < n && s[i] == '0') i++;
            }

            else if(s[i] == '1'){

                ones++;
                i++;
            }
        }

        return cnt;
    }
};