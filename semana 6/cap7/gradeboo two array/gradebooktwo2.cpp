// Fig. 7.20: fig07_20.cpp
// Creates GradeBook object using a two-dimensional array of grades.
#include <array>
#include "gradebook2.h" //GradeBook class definition
using namespace std;

int main(){
    array < array < int, GradeBook::tests >, GradeBook::students > grades{
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70},
        {87,96,70}
    };
    GradeBook myGradeBook("CS101 Introduction to C++ Programing",grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();

}
