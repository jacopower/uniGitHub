// classes2

#include <iostream>
#include <string>

using std::cin ;
using std::cout ;
using std::string ;


class complex  {
   private:                      // private code isn't accessible outside the class (can be called in the public part)
      double r ;
      double i ;

   public:                       // public code can be accessible in all the program (can be called, pointed referenced...)
      complex(double x, double y) : r{x}, i{y} {}        // when i create an objet of this type i need to put 2 argments in ()
   // complex(double x, double y) { r=x , i=y ; }        // does the same as line above
      complex()   { r=0 ; i=0 ; }                        // allows me to create a complex object without putting () and sets initial r, i

      double real()  { return r ; }                      // to return the real part of a complex
      void real(double ar) { r=ar ; }                    // to edit the real part of a complex

      double imag()  { return i ; }
      void imag(double ai) { i=ai ; }
} ;


int main()  {
   cout <<'\n' <<"Let's learn other about classes!" <<'\n' <<'\n' ;
      
   complex c1 ;
   cout <<c1.real() <<'\n' <<'\n';        // i'm adressing the method real() within the object c1 // 0
   
   c1.real(5) ;
   c1.imag(2) ;
// c1.i() =2 ;                         // error, c1.r is private, c1.real() is public
// c1.imag() ="string" ;               // error, the caratheristic 'imag' is double type
   cout <<c1.real() <<'\n' <<'\n';        // 5

   complex c2(3,6) ;
   cout <<c2.imag() <<'\n' <<'\n' ;       // 6

   complex c3 {9,10} ;
   cout <<c3.imag() <<'\n' <<'\n' ;       // 10
}
