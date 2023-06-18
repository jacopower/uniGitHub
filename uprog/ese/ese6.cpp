// ese6

#include <iostream>
#include <cmath>

using std::cin ;
using std::cout ;

struct complex {    double r ;
                    double i ;  
                } ;                                                 // the function struct creates a new type that can use/group multiple objects of different type

double normc(complex c) {   double result =c.r*c.r + c.i*c.i ;      // the . (dot) in 'c.r' allows to access a member of an object of a class type
                            return result ; }

complex operator==(complex lhs, complex rhs)   {   complex result ={lhs.r==rhs.r, lhs.i==rhs.i} ;
                                                return result ; }   // the function operator*(){} defines the function of a new operator

complex operator+(complex lhs, complex rhs) {   complex result ={lhs.r+rhs.r, lhs.i+rhs.i} ;
                                                return result ; }

void solvex(double a, double b, double c)   {   double delta = pow(b,2)-(4*a*c) ;
                                                double r1 =(-b+sqrt(delta))/(2*a) ;
                                                double r2 =(-b-sqrt(delta))/(2*a) ;
                                                if (delta<0)        {   cout << "impossible equation" ; }
                                                else if(delta==0)   {   cout <<r1 ; }
                                                else if(delta>0)    {   cout <<r1 <<", " <<r2 ; }
                                                return ;
                                            }

int main()  {   complex c1 ={1, 3} ;
                
                cout <<'\n' ;
                cout <<"Hi, I have one complex numbers c1={1, 3}, but I need another one...help me!" <<'\n' ;

                cout <<"give me the real part: " ;
                double r2 ;
                cin >>r2 ;

                cout <<"give me the imaginary part: " ;
                double i2 ;
                cin >>i2 ;

                complex c2 ={r2, i2} ;

                cout <<'\n' <<"the norm of this complex number is: " <<normc(c2) <<'\n' ;

                complex sum =c1+c2 ;
                cout <<"the sum of the two complex numbers is: {" <<sum.r  <<", " <<sum.i <<"}" <<'\n' <<'\n' ;    // idk how to print a complex number

                cout <<"Now, if you give me three parameters a, b, c, i will solve the corresponding second grade equation" <<'\n' ;

                cout <<"give me a, b, c:" <<'\n' ;
                int a, b, c ;
                cin >>a ;
                cin >>b ;
                cin >>c ;

                cout <<"the result is: " ;
                solvex(a, b, c) ;
                cout <<'\n' <<'\n' ;
            }
