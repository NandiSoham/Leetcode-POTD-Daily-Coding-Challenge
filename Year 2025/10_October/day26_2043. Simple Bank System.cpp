// Problem Link -> https://leetcode.com/problems/simple-bank-system/description/

class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || balance[account1-1] < money) {
            return false;
        }

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n)
            return false;
        
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || balance[account - 1] < money)
            return false;
        
        balance[account - 1] -= money;
        return true;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
