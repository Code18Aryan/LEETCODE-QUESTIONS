class Solution { // Ho
public:
    int minimumRecolors(string blocks, int k) {
        
        int cnt = 0;
        int n = blocks.size();

        int mini = 1e9;

        int i = 0, j = 0;

        while( j < n){
            
            if(blocks[j] == 'W') cnt++;

            if(j-i+1 == k){

                mini = min(mini,cnt);

                if(blocks[i] == 'W'){

                    cnt--;
                }

                i++;
            }

            j++;
        }

        return mini;
    }

};
