class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());

        string str1 = strs[0];
        string str2 = strs[strs.size()-1];

        int left = 0;
        int right = 0;

        string ans = "";

        while(left < str1.size() && right < str2.size()){

            if(str1[left] == str2[right]){

                ans += str1[left];

                left++;
                right++;
            }

            else break;
        }

       return ans;
        
    }
};