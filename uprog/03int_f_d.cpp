// int_f_d

#include <iostream>

using std::cout ;
using std::cin ;

int main()  {
    cout <<'\n' ;
    cout <<"I advise using 5, 5, 5.5, 5.5" <<'\n' <<'\n' ;

    cout <<"imput an int: " ;
    int i ;
    cin >>i ;
    cout <<"i = " <<i <<'\n' <<'\n' ;

    cout <<"imput a long int: " ;
    long li ;
    cin >>li ;
    cout <<"li = " <<li <<'\n' <<'\n' ;

    cout <<"imput a float: " ;
    float f ;
    cin >>f ;
    cout <<"f = " <<f <<'\n' <<'\n' ;

    cout <<"imput a double: " ;
    double d ;
    cin >>d ;
    cout <<"d = " <<d <<'\n' <<'\n' ;

    cout <<"i++ , ++i = " <<i++ <<" , " <<++i ;       // i , i+2
    cout <<"    f++ , ++f = " <<f++ <<" , " <<++f ;   // f , f+2 
    cout <<"    d++ , ++d = " <<d++ <<" , " <<++d ;   // d , d+2

//  cout <<f+=d ;    error f+=d: f and d are different types
//  cout <<f=+d ;    error "


    cout <<'\n' <<'\n' <<"int+float = " <<i+f <<'\n' <<'\n';       // 3 + 3.5 = 6.5
    cout <<"float+double = " <<f+d <<'\n' <<'\n';    // 3.3 + 2.2 = 5.5

    cout <<"int/3 = " <<i/3 <<'\n' <<'\n';           // 10 / 3 = 3
    cout <<"int/3.0 = " <<i/3.0 <<'\n' <<'\n';       // 10 / 3.0 = 3.3

    cout <<"float/3 = " <<f/3 <<'\n' <<'\n';         //
    cout <<"float/3.0 = " <<f/3.0 <<'\n' <<'\n';     //
    cout <<"double/3 = " <<d/3 <<'\n' <<'\n';        //

    cout <<"int/float = " <<i/f <<'\n' <<'\n';       //
    cout <<"float/double = " <<f/d <<'\n' <<'\n';    //

    cout <<"int*3 = " <<i*3 <<'\n' <<'\n';           //
    cout <<"float*3 = " <<f*3 <<'\n' <<'\n';         //
    cout <<"double*3 = " <<d*3 <<'\n' <<'\n';        //

    cout <<"int*float = " <<i*f <<'\n' <<'\n';       //

    cout << "NB :" <<'\n' ;
    cout <<" setprecision(n) before a float/double variable sets the precision of that number; " <<'\n' ;
    cout <<" maxprecision float = 2 ; maxprecision double = 7 ; maxprecision long double = ? " <<'\n' <<'\n' ;
}
