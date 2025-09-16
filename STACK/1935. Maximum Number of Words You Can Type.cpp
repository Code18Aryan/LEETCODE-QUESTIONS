class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int n = text.size();
        int m = brokenLetters.size();

        unordered_set<char> st;

        for(auto x : brokenLetters){

            st.insert(x);
        }

        int i = 0;
        int cnt = 0;

        while(i < n){

            bool check = true;

            while( i < n && text[i] != ' '){

                if(st.find(text[i]) != st.end()){

                    check = false;
                }

                i++;
            }

            if(check) cnt++;

            i++;
        }

        return cnt;
    }
};