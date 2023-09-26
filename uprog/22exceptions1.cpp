// exceptions1

#include <iostream>

using std::cin ;
using std::cout ;

double i ;

double f(double a)  {
   double result =0 ;

   try {   
      if(a==0) { throw a ; }                             // the try block needs to contain a throw block (otherwise error)
//    if(a==0) { throw i ; }                             // works as well (i just need to throw someting)
      result =2/a ;                                      // if something is thrown, nothing else in the try block is executed (after the throw)
   }
   catch(double aa) { cout<<"exception, denominator=0..." ; }  // if something is thrown this is executed instead
                                                               // a catch block needs a try block before (otherwise error)

// catch(int aa) { cout<<"exception, denominator=0..." ; }     // aborted, in the () is needed a new object of the same type of the thrown one

   return result ;
}

int main()  {
   cout <<'\n' <<"prova: a = " ;
   double a ;
   cin >> a ;

// if(a==2) { throw i ; }                                              // aborted, a throw block needs a catch block after

   cout <<'\n' <<f(a) <<'\n' <<'\n' ;
}
