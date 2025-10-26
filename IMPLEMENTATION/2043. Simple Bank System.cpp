// Ques Link - https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26

class Bank {
public:

    typedef long long ll;

    vector<ll> balance;
    int n;

    Bank(vector<long long>& balance) {
        
        this -> balance = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {

        if(account1 > n  || account2 > n) return false;
        
        if(balance[account1 - 1] < money) return false;

        balance[account2 - 1] += money;

        balance[account1 - 1] -= money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        
        if(account > n) return false;

        balance[account-1] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {

        if(account > n || balance[account-1] < money) return false;
    
        balance[account-1] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);

 */
