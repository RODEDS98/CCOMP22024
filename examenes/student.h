#include <iostream>
#include <string>
class Student {
    public:
        explicit Student(std::string n, int a):name{n} {      
            if (a >120){
            a = 18;
            }
        }

    std::string getName()   const{
        return name;

    }

    int getAge()    const{
        return age;

    }

    void setName(std::string n){
        name = n;
    }

    void setAge(int a){
        age=a;

    }           

    bool isOlde() const{
        if (age>18) 
            return true;
        else
            return false;
        
    }
    void displayStudent() const{
        std::cout <<"Ingreso del estudiante concretado: \n Nombre: "<< name <<" / Edad: "<< age << " / mayor de edad: " << isOlde() << std::endl;   //////////FALTA
    }  
        

    private:
        std::string name;
        int age;


};