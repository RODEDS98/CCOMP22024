# include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
public:
    explicit Student(std::string n, int a):
    name{n}, age{a}{
        
    }

    void setName(std::string n){
        name = n;
    }

    std::string getName() const{
        return name;
    }

    void setAge(int a){
        age = a;
    }

    int getAge() const{
        return age;
    }

    bool isOlder() const{
        
        return (age>=18);

    }
    

};