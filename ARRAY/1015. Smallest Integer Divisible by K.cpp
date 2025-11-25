class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if(k == 1) return 1;
        if(k % 5 == 0 || k % 2 == 0) return -1;

        int remainder = 0;

        for(int i=1; i<=k; i++){

            remainder = (remainder * 10 + 1) % k;
            
            if(remainder == 0) return i;
        }

        return -1;
    }
};