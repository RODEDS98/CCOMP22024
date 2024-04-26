// Fig. 3.5: AccountTest.cpp
// Using the Account constructor to initialize the name data
// member at the time each Account object is created.

#include <iostream>
#include "ejercicio3_9.h"

using namespace std;



int main() {

    int depositAmount;
    int withdrawAmount;
    string theName;

 // primer usuario
    Account account1{"Jane Green", 50};
    cout << "account1 name is: " << account1.getName() << endl;
    cout << "account1 : " << account1.getName() <<" balance is $"<<account1.getBalance()<< endl;



 // segundo usuario
    Account account2{"John Blue", -7};
    cout << "account2 name is: " << account2.getName() << endl;
    cout << "account2 : " << account2.getName() <<" balance is $"<<account2.getBalance()<< endl;

 // modificando el nombre del account1
    cout << "\n\nPlease enter the account name: ";

    getline(cin, theName);
    account1.setName(theName);

    cout << "Please enter the deposit amount: ";

    cin >> depositAmount;

    account1.deposit(depositAmount);

    cout << "\n\nInitial account1 name is: " << account1.getName();
    cout << "\nInitial account1 balance is: " << account1.getBalance();
    cout << "\nPlease enter a withdraw amount:\n";
 
    cin >> withdrawAmount;    
    account1.withdraw(withdrawAmount);

    //display balances

    cout << "\n\nInitial account1 name is: " << account1.getName();
    cout << "\nInitial account1 balance is: " << account1.getBalance();

 // modificando el nombre del account2
    cout << "\n\nPlease enter the account name: ";
    
    cin.ignore();
    getline(cin, theName);
    account2.setName(theName);

    cout << "Please enter the deposit amount: ";

    cin >> depositAmount;

    account2.deposit(depositAmount);

    cout << "\n\nInitial account1 name is: " << account2.getName();
    cout << "\nInitial account1 balance is: " << account2.getBalance();
    cout << "\nPlease enter a withdraw amount:\n ";
 
    cin >> withdrawAmount;    
    account2.withdraw(withdrawAmount);

    //display balances
    cout << "\n\nInitial account1 name is: " << account2.getName();
    cout << "\nInitial account1 balance is: " << account2.getBalance();


    return 0;
}
