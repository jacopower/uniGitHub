// classes3

#include <iostream>

using std::cin ;
using std::cout ;
using std::string ;


class complex  {  private:                      /* tips: private code is the code that you don want to be modifiable in the program,
                                                         (so this case is stupid because i wouldn't put r and i private if i want to be able to edit and use their content) */
                        double r ;
                        double i ;

                  public:                       // public code can be accessible in all the program (can be called, pointed referenced...)
                        complex(double x, double y) : r{x}, i{y}  {}
                     // complex(double x, double y)   { r=x , i=y ; }            // does same as line above
                        complex()   { r=0 ; i=0 ; }

                        double real()  { return r ; }                            // that's a method (member function): function defined in a class
                        void real(double ar) { r=ar ; }

                        double imag()  { return i ; }
                        void imag(double ai) { i=ai ; }                          /* i need both real(ar) and real() so that later i can use the function
                                                                                    with or without arguments, having different outcomes depending on what i need */

                        double norm2() {  double r = real()*real() + imag()*imag() ;         
                                                   return r ; }
               } ;

complex sumc(complex c1, complex c2)   {  complex c ;                            // just a free function
                                          c.real(c1.real()+c2.real()) ;
                                          c.imag(c1.imag()+c2.imag()) ;
                                          return c ;
                                       }

// choosing methods over functions helps when you have functions that deal with just one object of the class (i think), and to be organized when you have too many functions

int main()  {  cout <<'\n' <<"Let's learn other about classes!" <<'\n' <<'\n' ;
                
               cout <<"that's how i call a method: " <<'\n' <<'\n' ;
               
               complex c1 ;
               cout <<c1.real() <<'\n' <<'\n';                                               // calling a method

            // cout <<real() <<'\n' <<'\n';                                      // error, the function real() does not exist alone, it has to be associated to an object of the function's class
               
               c1.real(5) ;                                                                  // calling a method
               c1.imag(2) ;
               cout <<c1.real() <<'\n' <<'\n';

               complex c2(3,6) ;
               cout <<c2.imag() <<'\n' <<'\n' ;

               complex c3 {9,10} ;
               cout <<c3.imag() <<'\n' <<'\n' ;

               cout <<c1.norm2() <<", " <<c2.norm2() <<", " <<c3.norm2() <<'\n' <<'\n' ;     // calling a method // 29, 45, 181
               
               complex cr =sumc(c1,c2) ;                                                     // calling a free function (nothing new)
               cout <<cr.real() <<'\n' <<'\n' ;                                              // 5+3 = 8

               cout <<sumc(c2, c3).imag() <<'\n' <<'\n' ;                                    // 6+10 = 16
            }
