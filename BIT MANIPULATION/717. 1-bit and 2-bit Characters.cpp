class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();
        int len = 0;
        int i = 0;

        while(i < n){

            if(bits[i] == 1){

                i += 2;
                len = i;
            }

            else i++;
        }

        if((n-len) == 0) return false;

        return true;
    }
};