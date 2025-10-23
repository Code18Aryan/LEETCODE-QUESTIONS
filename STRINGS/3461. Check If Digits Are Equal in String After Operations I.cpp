//Ques Link - https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23

class Solution {
public:
    bool hasSameDigits(string s) {

        while(s.size() > 2){

            string temp = "";
            int index = 0;

            while(index < s.size()-1){

                int num = ((s[index] - '0' ) + (s[index+1] - '0')) % 10;
                temp += to_string(num);
                index++;
            }

            index = 0;
            s = temp;
        }

        cout<<s;

        return s[0] == s[1];
    }

};
