class Solution {
public:
    int minimumLength(string s) {

        int n = s.size();

        if( n < 3) return n;

        vector<int> frequency(26,0);

        int elementDeleted = 0;

        for(auto x : s){
             
             frequency[x - 'a'] ++;

             if(frequency[x - 'a'] == 3){
                 
                 frequency[x - 'a'] -= 2;

                 elementDeleted += 2;
             }
        }

        return n - elementDeleted;
        
    }
};