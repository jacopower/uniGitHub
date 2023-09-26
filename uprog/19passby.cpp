// passby

#include <iostream>

using std::cin ;
using std::cout ;

void pbValue(int x, int y) {
    int z;
    z=x ;
    x=y ;
    y=z ;

} ;

void pbReference(int& x, int& y) {
    int z;
    z=x ;
    x=y ;
    y=z ;

} ;

void pbAdress(int* x, int* y) {
    int z;
    z=*x ;
    *x=*y ;
    *y=z ;

} ;

int main() {
    cout <<'\n' <<"Let's learn a bit about pass by value/reference/adress !" <<'\n' <<'\n' ;
                
        int a=5, b=6 ;

        cout <<"Passing by value" <<'\n' ;
        cout <<"Before swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n' ;
        pbValue(a,b) ;
        cout <<"After swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n'<<'\n'  ;

    cout <<"the swapping occured only between the variables in the function scope, not affecting a and b" <<'\n' <<'\n' ;

        cout <<"Passing by reference" <<'\n' ;
        cout <<"Before swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n' ;
        pbReference(a,b) ;
        cout <<"After swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n' <<'\n' ;

    cout <<"since the variables in the function scope are references to a and b, the swapping affected a and b" <<'\n' <<'\n' ;

        cout <<"Passing by adress/pointer" <<'\n' ;
        cout <<"Before swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n' ;
        pbAdress(&a,&b) ;
        cout <<"After swapping: " <<'\n' <<"a=" <<a <<'\n' <<"b=" <<b <<'\n' <<'\n' ;

    cout <<"since the variables in the function scope are poiners to a and b, the swapping affected a and b" <<'\n' <<'\n' ;
}