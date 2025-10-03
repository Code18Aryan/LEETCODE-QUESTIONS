

class Solution {
  public:
  
    void solve(int index, string temp, vector<int>&arr, vector<string>&ans, unordered_map<int,string>&mpp){
        
        if(index >= arr.size()){
            
            ans.push_back(temp);
            
            return;
        }
        
        if(arr[index] == 1 || arr[index] == 0){
            
            solve(index + 1, temp, arr,ans,mpp);
        }
        
        
        int number = arr[index];
        string str = mpp[number];
        
        for(int i=0; i<str.size(); i++){
            
            temp.push_back(str[i]);
            
            solve(index + 1,temp, arr,ans,mpp);
            
            temp.pop_back();
        }
        
    }
  
    vector<string> possibleWords(vector<int> &arr) {
       
       vector<string> ans;
       unordered_map<int,string> mpp;
       
       mpp[2] = "abc";
       mpp[3] = "def";
       mpp[4] = "ghi";
       mpp[5] = "jkl";
       mpp[6] = "mno";
       mpp[7] = "pqrs";
       mpp[8] = "tuv";
       mpp[9] = "wxyz";
     
       
       solve(0,"",arr,ans,mpp);
       
       return ans;
    }
};

