class Solution {
public:

    bool checkSetBit(int n){

        unordered_map<char,int> mpp;

        while(n){

            mpp[n%2 + '0']++;
            n /= 2;
        }

        return mpp.size() == 1;
    }

    int smallestNumber(int n) {

        // Don't know how to solve this but this is my brute force 
        // need to learn bit manipulation
        
        for(int i=n; i<2024; i++){

            if(checkSetBit(i)) return i;
        }

        return -1;
    }
};