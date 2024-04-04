#include <iostream>
#include <string>
#include "student.h"
using namespace std;

int main(){

    string thename;
    int a;
    cout<<"prueba 1 : STUDENT"<<endl;
    cout<<"Ingrese los datos del estudiante"<<endl;

    cout<<"2Nombre: "<<endl;
    getline(cin,thename);

    cout<<"edad: "<<endl;
    cin>>a;

    Student estudiante1{thename,a};
    estudiante1.displayStudent();

    
 
    cout <<"\n Ingreso del estudiante concretado: \n Nombre: "<< estudiante1.getName()<<" / Edad: "<< estudiante1.getAge() << " / mayor de edad: " ;
    estudiante1.isOlde()? cout<<"Si"<<endl : cout<<"No" << endl;

    return 0;
    
}