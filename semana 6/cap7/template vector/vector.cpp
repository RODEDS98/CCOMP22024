// Fig. 7.21: fig07_21.cpp
// Demonstrating C++ Standard Library class template vector.
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

void outputVector(const vector<int>&); // display the vector
void inputVector(vector<int>&); // input values into the vector

int main() {

    vector<int> integers1(7); // 7-element vector<int>
    vector<int> integers2(10); // 10-element vector<int

    // print integers1 size and contents
    cout << "Size of vector integers1 is" << integers1.size() << "\nvector after initialization:";
    outputVector(integers1);

    // print integers2 size and contents
    cout << "\nSize of vector integers2 is " << integers2.size() << "\nvector after initialization:";
    outputVector(integers2);


    // input and print integers1 and integers2
    cout << "\nEnter 17 integers:" << endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "\nAfter input, the vectors contain:\n" << "integers1:";
    outputVector(integers1);
    cout << "integers2:";
    outputVector(integers2);


    // use inequality (!=) operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2) {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    // create vector integers3 using integers1 as an
    // initializer; print size and contents
    vector<int> integers3{integers1}; // copy constructor

    cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization: ";
    outputVector(integers3);

    // use overloaded assignment (=) operator
    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2; // assign integers2 to integers

    
    cout << "integers1: ";
    outputVector(integers1);
    cout << "integers2: ";
    outputVector(integers2);

    // use equality (==) operator with vector objects
    cout << "\nEvaluating: integers1 == integers2" << endl;

    if (integers1 == integers2) {
        cout << "integers1 and integers2 are equal" << endl;
    }

    // use square brackets to use the value at location 5 as an rvalue
    cout << "\nintegers1[5] is " << integers1[5];

    // use square brackets to create lvalue
    cout << "\n\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1: ";
    outputVector(integers1);

    // attempt to use out-of-range subscript
    try {
        cout << "\nAttempt to display integers1.at(15)" << endl;
        cout << integers1.at(15) << endl; // ERROR: out of range
    }
    catch (out_of_range& ex) {
        cerr << "An exception occurred: " << ex.what() << endl;
    }

    // changing the size of a vector
    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    integers3.push_back(1000); // add 1000 to the end of the vector
    cout << "New integers3 size is: " << integers3.size() << endl;
    cout << "integers3 now contains: ";
    outputVector(integers3);
}

// output vector contents
void outputVector(const vector<int>& items) {
    for (int item : items) {
        cout << item << " ";
    }

    cout << endl;
}

// input vector contents
void inputVector(vector<int>& items) {
    for(int& item : items){ 
         cin >> item;
    }
}
/*

Size of vector integers1 is 7
vector after initialization: 0 0 0 0 0 0 0
Size of vector integers2 is 10
vector after initialization: 0 0 0 0 0 0 0 0 0 0

Enter 17 integers:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
After input, the vectors contain:
integers1: 1 2 3 4 5 6 7
integers2: 8 9 10 11 12 13 14 15 16 17
Evaluating: integers1 != integers2
integers1 and integers2 are not equal
Size of vector integers3 is 7
vector after initialization: 1 2 3 4 5 6 7
Assigning integers2 to integers1:
integers1: 8 9 10 11 12 13 14 15 16 17
integers2: 8 9 10 11 12 13 14 15 16 17
Evaluating: integers1 == integers2
integers1 and integers2 are equal
integers1[5] is 13
Assigning 1000 to integers1[5]
integers1: 8 9 10 11 12 1000 14 15 16 17
Attempt to display integers1.at(15)
An exception occurred: invalid vector<T> subscript
Current integers3 size is: 7
New integers3 size is: 8
integers3 now contains: 1 2 3 4 5 6 7 1000
/**/