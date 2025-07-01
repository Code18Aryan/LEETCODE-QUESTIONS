class Solution {
public:
    int possibleStringCount(string word) {

        int n = word.size();

        if( n == 0) return 0;

        int cnt = 1;

        for(int i=1; i<word.size(); i++){

             if(word[i] == word[i-1]) cnt++;
        }

       return cnt;
    
        
    }
};