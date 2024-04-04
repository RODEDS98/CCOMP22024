#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int main(){

    Date fecha1{3,1,2024};
    Date fecha2{15,14,2048};
    Date fecha3{20,12,2003};

    fecha1.displayDate();
    fecha1.isLeapYear()? cout<<"Si"<<endl : cout<<"No" << endl;

    fecha2.displayDate();
    fecha2.isLeapYear()? cout<<"Si"<<endl : cout<<"No" << endl;

    fecha3.displayDate();
    fecha3.isLeapYear()? cout<<"Sio"<<endl : cout<<"No" << endl;

    return 0;

}