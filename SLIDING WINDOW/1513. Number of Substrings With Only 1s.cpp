class Solution {
public:

    long long mod = 1e9 + 7;

    long long count(long long n){

        return (n*(n+1)/2 % mod);
    }

    int numSub(string s) {
        
        int cnt =  0;
        int i = 0, n = s.size();
        int mod = 1e9 + 7;

        while(i < n){

            if(s[i] == '0'){

                i++;
            }

            else{

                long long ones = 0;

                while(i < n && s[i] == '1'){

                    ones += 1;
                    i++;
                }

                cnt += (count(ones) % mod);
            }
        }

        return cnt % mod;
    }
};