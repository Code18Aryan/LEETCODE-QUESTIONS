#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&nums){
    
    for(auto x : nums){
        
        cout<<x<<" ";
    }
    
    cout<<endl;
}

int main() {
	
	string s1 = "ALL IS WELL";
	string keyword = "CAKE";
	
    string text = "";
    
    for(auto x : s1){
        
        if(x == ' ') continue;
        
        else text += x;
    }
    
	//cout<<text;
	
	vector<int> num1;
	vector<int> num2;
	
	for(int i=0; i<text.size(); i++){
	    
	    num1.push_back(text[i] - 'A');
	}
	
	for(int i=0; i<keyword.size(); i++){
	    
	    num2.push_back(keyword[i] - 'A');
	}
	
// 	print(num1);
// 	print(num2);

    int index = 0;

    vector<int> ans(max(num1.size(),num2.size()));
    
    for(int i=0; i<max(num1.size(),num2.size()); i++){
        
        ans[i] = (num1[i] + num2[index]) % 26;
        
        index++;
        
        if(index == num2.size()){
            
            index = 0;
        }
    }
    
    print(ans);
    
    string cipher = "";
    
    for(auto x : ans){
        
        cipher += x + 'A';
    }
    
    cout<<"The Cipher text is "<<cipher<<endl;
    
    
    
    
	
	

}
