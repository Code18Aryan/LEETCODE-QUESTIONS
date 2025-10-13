#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}
class Solution {
public:

    bool isAnagram(string &a, string &b){

        unordered_map<char,int> mpp;

        for(auto x : a){

            mpp[x]++;
        }

        for(auto x : b){

           mpp[x]--;
           if(mpp[x] == 0) mpp.erase(x);
        }

        return mpp.empty();
    }

    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;
        deque<string> dq;

        for(auto &x : words){

            if(dq.empty()) dq.push_back(x);

            else{

                if(!dq.empty() && isAnagram(dq.back(),x)){

                    continue;

                }

                else dq.push_back(x);
            }

        }

        for(auto &x : dq){

            ans.push_back(x);
        }
        
        return ans;
    }
};





// Another space optimized code using without deque

class Solution {
public:

    bool isAnagram(string &a , string &b){

        unordered_map<char,int> mpp;

        for(auto x : a) mpp[x]++;

        for(auto x : b){

            mpp[x]--;

            if(mpp[x] == 0) mpp.erase(x);
        }

        return mpp.empty();
    }

    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;

        for(auto x : words){

            if(ans.empty()) ans.push_back(x);
            
            else{

                if(!ans.empty() && isAnagram(ans.back(),x)){

                    continue;
                }

                else ans.push_back(x);
            }
        }

        return ans;
    }
};
