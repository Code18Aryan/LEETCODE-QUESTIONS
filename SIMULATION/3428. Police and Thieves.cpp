class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        
        vector<int> police,theif;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            
            if(arr[i] == 'P'){
                
                police.push_back(i);
            }
            
            else theif.push_back(i);
        }
        
        int i = 0, j = 0, a = police.size(), b = theif.size(), cnt = 0;
        
        while(i < a && j < b){
            
            if(abs(police[i] - theif[j]) <= k){
                
                cnt++;
                i++; 
                j++;
            }
            
            else if(theif[j] > police[i]){
                
                i++;
            }
            
            else j++;
        }
        
        return cnt;
    }
};