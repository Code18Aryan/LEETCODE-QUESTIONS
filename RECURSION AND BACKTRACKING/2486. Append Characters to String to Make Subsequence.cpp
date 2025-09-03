#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    void getSubsequence(int index, string str, vector<string>& subSequence, string &s){

        if(index >= s.size()){

            if(!str.empty()){

                subSequence.push_back(str);
            }

            return;
        }

        getSubsequence(index + 1, str + s[index], subSequence, s);
        getSubsequence(index + 1, str , subSequence,s);

    }

    int getLength(string &a, string &b){

        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;

        while(i < n && j < m){

            if(a[i] != b[j]) return j;

            i++;
            j++;
        }

        return j;

    }

public:
    int appendCharacters(string s, string t) {

        /*
        
        vector<string> subSequence;

        getSubsequence(0,"",subSequence, s);

        int maxi = 0;

        for(auto x : subSequence){

            int maxLengthMatch = getLength(x,t);

            maxi = max(maxi, maxLengthMatch);
        }

        cout<< maxi;

        return t.size() - maxi; */

        //2nd Appraoch using two pointer - ⚔️ 😂

        int n = s.size(), m = t.size(), i=0, j=0;

        while(i < n && j < m){

            if(s[i] == t[j]){

                j++;
            }

            i++;
        }

        return m-j;
    }
};
