class Solution {
public:

    bool isValidBusiness(string &str){

        return (str == "electronics") || (str == "grocery") || (str == "pharmacy") || (str == "restaurant");
    }

    bool check(string &code){

        for(auto &x : code){
            
            if(x == '_') continue;
            if(!isalnum(x)) return false;
        }

        return true;
    }

    void putIntoAns(unordered_map<string,vector<string>> &mpp, vector<string>&ans){

        vector<string> first = mpp["electronics"];
        vector<string> second = mpp["grocery"];
        vector<string> third = mpp["pharmacy"];
        vector<string> fourth = mpp["restaurant"];

        for(auto &x : first) ans.push_back(x);
        for(auto &x : second) ans.push_back(x);
        for(auto &x : third) ans.push_back(x);
        for(auto &x : fourth) ans.push_back(x);
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<string> ans;
        map<string,multiset<string>> mpp;

        for(int i=0; i<code.size(); i++){

            if(check(code[i]) && isValidBusiness(businessLine[i]) && isActive[i]){

                if(code[i] == "") continue;
                mpp[businessLine[i]].insert(code[i]);
            }
        }

        for(auto &x : mpp){

            multiset<string> st = x.second;

            for(auto &y : st) ans.push_back(y);
        }

        return ans;
    }
};