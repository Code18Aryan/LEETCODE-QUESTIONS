class Solution {
public:
    string clearDigits(string s) {

        int n = s.size();

        deque<char> dq;

        string ans = "";

        for(int i=0; i<n; i++){

            if(dq.empty()) dq.push_back(s[i]);

            else{

                if(!dq.empty() && s[i] >= 48 && s[i] <= 57){

                    dq.pop_back();
                }

                else dq.push_back(s[i]);
            }
        }

        for(auto x : dq){

            if(x >= 48 && x <= 57) continue;
            else ans += x;
        }

        return ans;
        
    }
};