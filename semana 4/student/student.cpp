#include <iostream>
#include "Student.h"

using namespace std;


int main() {

    string name;
    int age;

// Creando primero los parametros y luego el objeto
    cout << "\nIngrese nombre del primer estudiante : ";
    getline(cin, name);
    cout << "Ingrese la edad del primer estudiante : ";
    cin >> age;

    Student estudiante1{name, age};
    cout << "\nNombre primer estudiante:\n " << estudiante1.getName() << endl;
    cout << "Edad primer estudiante:\n " << estudiante1.getAge() << endl; 
    cout << "Mayor de edad: " << ( (estudiante1.isOlder()) ? "Si" : "No" ) << endl;
    

 // Creando primero el objeto vacio y luego usando sus metodos
 // para ingresar el nombre y la edad.  

    Student s2{" ",0};
    cout << "Ingrese nombre del segundo estudiante : ";

    cin.ignore();
    getline(cin, name);
    s2.setName(name);

    cout << "\nIngrese la edad del segundo estudiante : ";
    cin >> age;
    s2.setAge(age);

    cout << "\nNombre segundo estudiante :\n " << s2.getName() << endl;
    cout << "Edad segundo estudiante :\n " << s2.getAge() << endl; 
    cout << "Mayor de edad : " << ( (s2.isOlder()) ? "Si " : "No " ) << endl;

    return 0;
}