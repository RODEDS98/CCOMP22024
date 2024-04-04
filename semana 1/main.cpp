// Fig. 3.5: AccountTest.cpp
// Using the Account constructor to initialize the name data
// member at the time each Account object is created.

#include <iostream>
#include "Account.h"

using namespace std;

int main() {
 // create two Account objects
    Account account1{"Jane Green", 50};
    Account account2{"John Blue", -7};


 // display initial value of name for each Account
    cout << "account1 name is: " << account1.getName() << endl;
    cout << "account2 name is: " << account2.getName() << endl;
//display initial balane of each object
    cout << "account1 : " << account1.getName() <<"balane is $"<<account1.getBalance()<< endl;
    cout << "account2 : " << account2.getName() <<"balane is $"<<account2.getBalance()<< endl;

int depositAmount;
cin>> depositAmount;

    cout << "adding"<< depositAmount <<"to account1 balance"<< endl;
    account1.deposit(despositAmount);

    //display balances
 

    cout << "\n Enter deposit amount for account2: " ;
    cin >> depositAmount;
    cout << "Adding" << depositAmount<<"to account2 balance";
    account2.deposit(depositAmount);

    //display balances

    cout << "\n account1:" << account1.getName() << "Balance is $"<< account1.getBalance();
    cout << "\n account2:" << account2.getName() << "Balance is $"<< account2.getBalance()<<endl;

}
