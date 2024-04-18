
// Using the Account constructor to initialize the name data
// member at the time each Account object is created.

#include <iostream>
#include <cmath>


using namespace std;

int getTamano(long long a){
    long long t{0},b{0};
    b=a;
    cout<<"Ingrese un numero"<<endl;

    while (!(b/10==0)){
        b=b/10;
        t++;
    }
    return t+1;
}

int main() {

    long long a{0}, a_1 , t_1 ;
    int j{1};
    cout<<"Ingrese un numero"<<endl;
    cin>>a;
    int t = getTamano(a);
    a_1 = a;
    t_1 = t;

    //int x = pow(10,t_1 -1);    
    //cout<< a_1/x <<endl;              // 1234321                                                   23432                343  4
    for (int i=1; i<= t/2 ; i++){      //   i=1       i=2 
        long long x = pow(10,t_1 -1);          //   t_1=7(x=1000 000)                                t_1=5(x=100 00)                             3  1
        //                               //     
        j=i;
        if(a_1 % 10 == a_1/x){   //   a_1 % 10= 1  ==  a_1/pow(10,1000 000)  /// //   a_1 % 10= 2  ==  a_1/pow(10,100  00)
                                         //   a_1 % 10= 1  ==   1(234321)/1000 000  /// //    a_1 % 10= 2  ==  2(3432)/1000 000
                                         
            a_1 = a_1 % x;       // a_1 % 1000 000 =   1(234321) 
            a_1 = a_1/10;        // 234321/10  =  (23432)
            t_1=t_1-2;           //t_1=7(x=1000 000)
            continue;
        }
        else 
            break;        
    }
    j==t/2?cout<<"Si es palidromo"<<endl:cout<<"No es palidromo"<<endl;
    return 0;

}