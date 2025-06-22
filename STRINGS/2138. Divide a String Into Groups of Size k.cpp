class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> ans(ceil((double)s.size()/k));

        int j = 0;
        int i = 0;

        int n = s.size();

         while(i < n){

            string temp = "";

            for(int j=0; j<k; j++){

                if(i < n){

                    temp += s[i];
                    i++;
                }

                else temp += fill;
            }

            ans[j] = temp;

            j++;
        }

        return ans;
    }
};