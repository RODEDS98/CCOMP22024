
//ejercicio 3.12

#include <iostream>
#include <string>

class Date{
    public:
        explicit Date(int m , int d, int y) :day{d}, year{y} {
            if ( m >= 1 && m<=12)            {
                month =m;
            }
            if ( y >= 2051 && y<=1899)            {
                year =1900;
            }
            
        }
        void setDay(int d){
            day =d;
        }
        
        void setMonth(int m){
            month =m;
        }

        void setYear(int y){
            year= y;
        }

        int getDay() const{
            return day;
        }
        int getYear() const{
             return year;
        }
        
        int getMonth() const{
             return month;
        }

        void displayDate() const{
            std::cout << day <<"/"<< month << "/" << year << std::endl;   //////////FALTA
        }

        bool slLeapYear() const{
            if (year)
        }
    private:
        int day;
        int year;
        int month{1};

};