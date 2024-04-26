
//ejercicio 3.12

#include <iostream>

using namespace std;

class Date{
public:
    explicit Date(int d, int m, int y) {
        setYear(y);
        setMonth(m);
        setDay(d);    
    }

    int getDay() const{
        return day;
    }

    int getMonth() const{
        return month;
    }

    int getYear() const{
        return year;
    }

    void setDay(int d){
        if (d > 0) {
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (d >= 1 && 30 >= d) {
                    day = d;
                } else {
                    cout << "Este mes solo tiene 30 días" << endl;
                }
            } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (d >= 1 && 31 >= d) {
                    day = d;
                } else {
                    cout << "Este mes solo tiene 31 días" << endl;
                }
            } else if (month == 2 && isLeapYear()) {
                if (d >= 1 && 29 >= d) {
                    day = d;
                } else {
                    cout << "Es año bisciesto, febrero tiene 29 días" << endl;
                }
            } else if (month == 2 && !isLeapYear()) {
                if (d >= 1 && 28 >= d) {
                    day = d;
                } else {
                    cout << "Este mes solo tiene 28 días" << endl;
                }
            }
        } else {
            cout << "No puedes ingresar un dia \"0\"" << endl;
        }
    }

    void setMonth(int m){
        if(m >= 1 && m <= 12) {
            month = m;
        }
    }

    void setYear(int y){
        if(y>= 1900 && y <=2050) {
            year = y;
        }
    }


    //Crishofer, año biciesto, print, print año biciesto
    bool isLeapYear() const {
        if ((!(year % 4) && (year % 100)) || (!(year % 400))) {
            return true;
        } else {
            return false;
        }
    }

    void displayDate() const {
        cout << "The Date is " << day << "/" << month << "/" << year << endl;
    } 

    void printLeapYear() const {
        if (isLeapYear()) {
            cout << year << " es año biciesto" << endl;
        } else {
            cout << year << " no es año biciesto" << endl;
        }
    }        
    
private:
    
    int day{1};
    int month{1};
    int year{1900};

};