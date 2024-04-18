//ejercicio 3.12

#include <iostream>
#include <string>

class Date{
    public:
        explicit Date(int m , int d, int y) :day{d}, year{y} {
            setDay(d);
            setMonth(m);
            setYear(y);  
        } 

        void setDay(int d){
                
        if (d >=1 && d <=31){
            if (isLeapYear() && month ==2){   //Si es viciesto y el mes es febrero:
                do {
                    std::cout<<"ingrese un dia valido para el mes de febrero en año viciesto"<<std::endl;                
                }
                while (!(d >=1 && d <=29));
                    day =d; 
                }
                else if (!(isLeapYear()) && month ==2){
                    do {
                        std::cout<<"ingrese un dia valido para el mes de febrero "<<std::endl;                
                    }
                    while (!(d >=1 && d <=28));
                        day =d; 
                }
                else if ((month == 4 || month ==6 || month == 9 || month == 11 ) && (day  <= 31 || day >= 1 ))

                    day =d;

                else {
                    do {
                    std::cout<<"ingrese un dia valido para un mes de solo 30 dias "<<std::endl;                
                    }
                    while (!(d >=1 && d <=30));
                    day =d;

                }
            }

        }
        
        void setMonth(int m){

            do {
                std::cout<<"ingrese un mes valido"<<std::endl;                
            }
            while (!(m >=1 && m <=12));
            month =m;
        }

        void setYear(int y){
            if (!(y<2183 && y>1900)) {
                y=1500;
            }
            else
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