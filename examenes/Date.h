
//ejercicio 3.12

#include <iostream>
#include <string>

class Date{
    public:
        explicit Date(int m , int d, int y) :day{d}, year{y} {
            if ( m >= 1 && m<=12)            {
                month =m;
            }
            if ( y >= 2051 || y<=1899)            {
                year =1900;
            }
            if (d >=1 && d <=31)
                month =m;
            
        }
        void setDay(int d){
                
            do {
                std::cout<<"ingrese un dia valido"<<std::endl;                
            }
            while (!(d >=1 && d <=31));
            day =d;

        }
        
        void setMonth(int m){

            do {
                std::cout<<"ingrese un mes valido"<<std::endl;                
            }
            while (!(m >=1 && m <=12));
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

        bool isLeapYear() const{
            if ((year % 4==0 && year%100 != 0) || (year%400==0) ) 
                return true;            
            else
                return false;
        }


        
        

    private:
        int day;
        int year;
        int month{1};

};