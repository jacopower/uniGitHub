// enumerations

#include <iostream>
#include <string>

using std::cin ;
using std::cout ;
using std::string ;
using std::runtime_error ;


int main() {
    cout <<'\n' <<"Let's learn a bit about enumerations..." <<'\n' <<'\n' ;
    cout <<"enum is a type that can have multiple values" <<'\n' <<'\n' ;

    enum Color {red, green, blue, purple, orange} ;
//  enum Color::yellow =5 ;     // error, cannot add items to an existing enum
//  enum Color2 {red, green, blue, purple, orange} ;        // error, cannot initialize an enum with words already assigned to an other enum


    cout << orange <<'\n' ;      // 4

    Color mycolor = blue ;
    cout << mycolor <<'\n' <<'\n' ;     // 2

//  mycolor = 4 ;               // error, cannot set an enum type object as an int type object
//  Color yourcolor = 1 ;       // error, cannot initialize an enum type object as an int type object


    enum Car {ferrari=300, lamborghini=280, porche=230, mclaren=350, maserati=250} ;

    Car winner=porche ;

    cout <<"Let's race! Pick two car between ferrari(0), lamborghini(1), porche(2), mclaren(3), maserati(4): " <<'\n' ;

    int p1 ;
    cin >>p1 ;

    int p2 ;
    cin >>p2 ;

    try {
        Car pick1 =(Car)p1 ;
        Car pick2 =(Car)p2 ;

//    try {
//        if() throw{Car pick1 =(Car)p1 ; }
//        if() throw{Car pick2 =(Car)p2 ; }
//    }   catch(Car e){cout <<"not an option" <<'\n' <<'\n' ;}

        if (pick1>pick2) {winner =pick1 ;}
        else if(pick2>pick1) {winner =pick2 ;}
    }   catch(runtime_error e) {cout <<'\n' <<"not an option" <<e.what() <<'\n' <<'\n' ;}

    string w ;
    switch (winner) {
        case 300: w="ferrari" ;
        case 280: w="lamborghini" ;
        case 230: w="porche" ;
        case 350: w="mclaren" ;
        case 250: w="maserati" ;
        break ;
    }              

    cout <<"The winner is... " <<w <<'\n' <<'\n' ;

    
    Car top =porche ;

    if(ferrari>=top) {top=ferrari ;}
    if(lamborghini>=top) {top=lamborghini ;}
    if(maserati>=top) {top=maserati ;}
    if(porche>=top) {top=porche ;}
    if(mclaren>=top) {top=mclaren ;}
    
    string name ;

    switch (top) {
        case 300: name="ferrari" ;
        case 280: name="lamborghini" ;
        case 230: name="porche" ;
        case 350: name="mclaren" ;
        case 250: name="maserati" ;
        break ;
    }              

    cout << "the fastest car is: " <<name <<", with a speed of: " <<top <<"km/h" <<'\n' <<'\n' ;     // mclaren, 350

//  cout <<"choose a color between red, green, blue, purple, orange: " ;
//  Color c ;
//  cin >> c;
//  cout <<"you chose color number: " <<c <<'\n' <<'\n';

}
