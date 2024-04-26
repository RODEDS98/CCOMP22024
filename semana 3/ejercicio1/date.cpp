#include <iostream>
#include "Date.h"

using namespace std;

int main(){

    Date mybirthday{3,7,1998};
    mybirthday.displayDate();

    Date fecha2{9, 11, 2001};
    fecha2.displayDate();

    Date fechaerror{20,50,9999};
    fechaerror.displayDate();


    return 0;    
}
