#include <bits/stdc++.h>

using namespace std;

class Solution {
    public: int maxScore(string s) {


        // ANS QUATION 0L + 1R MAXI

        //   1T = 1L + 1R

        // SUBSTITUTE 0L + (1T - 1L)
        //  FINAL -  0L - 1L + 1T

        int totalOne = count(s.begin(), s.end(), '1');

        int one = 0;
        int zero = 0;

        int result = -1e9;

        for (int i = 0; i < s.size() - 1; i++) {

            if (s[i] == '1') one += 1;
            else zero += 1;

            result = max(result, (zero - one));
        }

        return result + totalOne;
    }
};

int main() {



}