class Solution {
public:

    bool isVowel(string str){
         
        if((str[str.size()-1] == 'a' || str[str.size()-1] =='e' || str[str.size()-1] =='i' || str[str.size()-1] =='o' || str[str.size()-1] =='u') && (str[0] == 'a' || str[0] =='e' || str[0] =='i' || str[0] =='o' || str[0] =='u')) return true;

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> ans;

        vector<int> preSum(words.size());

        int sum = 0;

        for(int i=0; i<words.size(); i++){
             
              string str = words[i];

              // 

              if(isVowel(str)) sum++;

              preSum[i] = sum;
        }

        for(auto &x : queries){

             int start = x[0];
             int end = x[1];

             int cnt = preSum[end] - ((start > 0) ? preSum[start-1] : 0) ;

             ans.push_back(cnt);
        }

        return ans;
        
    }
};