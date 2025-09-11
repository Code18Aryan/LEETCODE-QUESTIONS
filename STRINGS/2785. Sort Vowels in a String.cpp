class Solution {
public:

    bool isVowel(char s){

        if(s == 'a' || s == 'e' ||s == 'i' || s == 'o' ||s == 'u' ||s == 'A' ||s == 'E' ||s == 'I' ||s == 'O' ||s == 'U' ){

            return true;
        }

        return false;
    }

    string sortVowels(string s) {
        
        string vowels = "";
        int j = 0;

        for(auto &x : s){

            if(isVowel(x)){

                vowels += x;
            }
        }

        sort(vowels.begin(),vowels.end());

        for(int i=0; i<s.size(); i++){

            if(isVowel(s[i])){

                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};