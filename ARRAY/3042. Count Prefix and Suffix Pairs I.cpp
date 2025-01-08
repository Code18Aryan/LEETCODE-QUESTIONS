class Solution {
public:

    bool isPrefixAndSuffix(string str1 , string str2){
         
          int n = str1.size();
          int m = str2.size();

          if( m < n) return false;

          int low = 0;
          int high = m-1;
          int index = 0;

          while( low < m){
             
             if(index == n) break;

             if(str2[low++] != str1[index++]) return false;
          }

          reverse(str1.begin(),str1.end());

          index = 0;

          while( high >= 0){
             
             if(index == n) break;

             if(str2[high--] != str1[index++]) return false;
          }

         return true;

    }

    int countPrefixSuffixPairs(vector<string>& words) {

        int cnt = 0;

        for(int i=0; i<words.size(); i++){
             
             for(int j=i+1; j<words.size(); j++){
                 
                  if(isPrefixAndSuffix(words[i],words[j])) cnt++;
             }
        }

        return cnt;
        
    }
};