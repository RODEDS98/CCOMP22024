// Fig. 3.8: Account.h
// Account class with name and balance data members, and a
// constructor and deposit function that each perform validation.
#include <string>
#include <iostream>

class Account {
    public:
    // Account constructor with two parameters
    
    explicit Account(std::string accountName, int initialBalance)
        : name{accountName} { // assign accountName to data member name
        // validate that the initialBalance is greater than 0; if not,
        // data member balance keeps its default initial value of 0
        if (initialBalance >0){
            balance= initialBalance;
        }
    }
    // function that sets the name
    
    void deposit(int depositAmount) {
        if (depositAmount){
            balance= balance + depositAmount; 
        }
    }
    // function that returns the name
    int getBalance()const{
        return balance;
    }

    void setName(std::string accountName) {
        name = accountName;
    }

    std::string getName() const {
        return name;
    }

    void withdraw(int withdrwalAmount){
        if(withdrwalAmount < balance){
           balance = balance - withdrwalAmount; 
        }
        else{
            std::cout << "cant Withdrawal " << std::endl; 
        }
    } 




    private:
        std::string name; // account name data member
        int balance{0}; //data member with defalut initial value
}; // end class Account