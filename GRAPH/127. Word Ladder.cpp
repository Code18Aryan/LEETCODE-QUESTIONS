class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){

            string currentWord = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(currentWord == endWord) return steps;

            for(int i=0; i<currentWord.size(); i++){

                char current = currentWord[i];

                for(int j=97; j<=122; j++){

                    currentWord[i] = j;

                    if(st.find(currentWord) != st.end()){

                        q.push({currentWord,steps+1});
                        st.erase(currentWord);
                    }

                }

                currentWord[i] = current;
            }
        }

        return 0;
    }
};