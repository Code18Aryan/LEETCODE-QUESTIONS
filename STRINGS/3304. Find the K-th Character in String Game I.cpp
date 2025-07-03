class Solution {
public:
    char kthCharacter(int k) {
        
        string word = "a";

        while(word.size() < k){

            string temp = word;

            for(int i=0; i<temp.size(); i++){

                int ascii = temp[i];

                if(temp[i] == 'z') temp[i] = 'a';

                else temp[i] = ascii + 1;
            }

            word += temp;
        }

        return word[k-1];
    }
};