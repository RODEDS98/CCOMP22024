#include <iostream>
#include "Date.h"

using namespace std;

int main(){

    int d,m,y;
    Date mybirthday{3,7,1998};
    mybirthday.displayDate();

    Date fecha2{9, 11, 2001};
    fecha2.displayDate();

    Date fechaerror{20,50,9999};
    fechaerror.displayDate();

    Date fechaprueba{1,1,1};

    cin>>m;
    fechaprueba.setMonth(m); 
    cin>>y;    
    fechaprueba.setYear(y);
    cin>>d;
    fechaprueba.setDay(d);



    return 0;    
}
