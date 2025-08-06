class Solution {
  public:
    int romanToDecimal(string &s) {
        
        
        vector<int> number = {1000,500,100,50,10,5,1};

        vector<char> symbol = {'M','D','C','L','X','V','I'};

        unordered_map<char,int> mpp;

        for(int i=0; i<7; i++){

             mpp[symbol[i]] = number[i];
        }

        int ans = 0;

        for(int i=0; i<s.size(); i++){

            if(mpp[s[i]] < mpp[s[i + 1]]) ans -= mpp[s[i]];

            else ans += mpp[s[i]];
        }

      return ans;
  
    }
};