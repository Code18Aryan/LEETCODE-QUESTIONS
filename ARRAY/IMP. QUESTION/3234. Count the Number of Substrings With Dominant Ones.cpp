class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size(), cnt = 0;

        vector<int> suff(n);

        for(int i = n - 1; i >= 0; --i) {

            suff[i] = cnt;

            if(s[i] == '1')cnt++;
            else cnt = 0;
        }

        int ans = 0;

        for(int i = 0; i * i <= n; ++i) {

            int zero = i, one = max(1, i * i);

            int low = 0, high = 0, zeroCnt = 0, oneCnt = 0;

            while(high < n) {

                s[high] == '1' ? oneCnt++ : zeroCnt++;

                while(zeroCnt > zero) {

                    s[low] == '1' ? oneCnt-- : zeroCnt--;
                    low++;
                }

                while(zeroCnt == zero && oneCnt >= one) {

                    ans += suff[high] + 1;
                    s[low] == '1' ? oneCnt-- : zeroCnt--;

                    low++;
                }
                high++;                    
            
            }
        }

        return ans;
    }
};