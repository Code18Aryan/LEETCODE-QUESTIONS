#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    bool isSubsequence(string s, string t, int m, int n){

        if(n == 0) return true;
        if(m == 0) return false;

        if(s[m-1] == t[n-1]){

            return isSubsequence(s, t, m-1, n-1);
        }

        else return isSubsequence(s, t, m-1, n);

    }

};
                 
int main(){
           
    Solution sol;

    
    bool check = sol.isSubsequence("ARYAN", "YN", 5, 2);

    cout<<check<<endl;

            
    return 0;
}