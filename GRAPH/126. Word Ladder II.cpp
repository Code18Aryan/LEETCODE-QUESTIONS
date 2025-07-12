class Solution{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_set<string> toErase;
        st.erase(beginWord);
        q.push({beginWord});

        while(!q.empty()){

            int size = q.size();

            while(size--){

                vector<string> seq = q.front();
                q.pop();

                string word = seq.back();

                if(word == endWord){

                    if(ans.empty()){

                        ans.push_back(seq);
                    }

                    else if(ans.back().size() == seq.size()){

                        ans.push_back(seq);
                    }
                }

                for(int i=0; i<word.size(); i++){

                    char original = word[i];

                    for(char ch = 'a'; ch<='z'; ch++){

                        word[i] = ch;

                        if(st.find(word) != st.end()){

                            seq.push_back(word);
                            q.push(seq);
                            seq.pop_back();
                            toErase.insert(word);
                        }

                    }

                    word[i] = original;
                }
            }

            for(auto x : toErase){

                st.erase(x);
            }

            toErase.clear();
        }

        return ans;
    }
};