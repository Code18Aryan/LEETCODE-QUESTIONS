problem link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11
class Solution {
public:
    string removeOccurrences(string s, string part) {

        string ans = "";

        int n = s.size();
        int m = part.size();

        if(m > n) return s;

        for(int i=0; i<n; i++){

            ans += s[i];

            if(ans.size() >= m && ans.substr(ans.size() - m) == part){

                ans.erase(ans.size()- m);
            }

        }

        return ans;
        
    }
};