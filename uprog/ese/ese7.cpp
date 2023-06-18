// ese7

#include <iostream>
#include <cmath>

using std::cin ;
using std::cout ;

// using a class is stupid because i dont need anything private, so i'm going to use a struct


int gcd(int n1, int n2) {   int result=1 ; 
                            int i =1 ;
                            int an1 =abs(n1) ;
                            int an2 =abs(n2) ;
                            
                            if(an1>an2) {   for(; i<=an2; ++i)  {   int rest1 =an1%i ;
                                                                    int rest2 =an2%i ;
                                                                    if((rest1==0)&&(rest2==0)) { result =i ; }
                                                                }
                                        }
                                else    {   for(; i<=an1; ++i)  {   int rest1 =an1%i ;
                                                                    int rest2 =an2%i ;
                                                                    if((rest1==0)&&(rest2==0)) { result =i ; }
                                                                }
                                        }

                            return result ;
                        }

class rational  {   private:

                    public:
                            int n ;
                            int d ;

                            int num()   {   if(d>0) return n/gcd(n,d) ;
                                            else    return -n/gcd(n,d) ; }
                            int den()   {   return abs(d)/gcd(n,d) ; }

                            double res = n/d ;

                            rational() { n=1; d=1 ; }
                            rational(int an, int ad)    {   n=an ; d=ad ; }
                } ;

bool operator==(rational lhs, rational rhs) {   return ( lhs.res==rhs.res && lhs.num()==rhs.num() && lhs.den()==rhs.den() ) ; }

rational operator+(rational lhs, rational rhs)  {   rational r ;
                                                    r.n = (lhs.n*rhs.d)+(rhs.n*lhs.d) ; r.d = lhs.d*rhs.d ;
                                                    return r ; }

rational operator*(rational lhs, rational rhs)  {   rational r ;
                                                    r.n = lhs.n*rhs.n ; r.d = lhs.d*rhs.d ;
                                                    return r ; }

rational operator/(rational lhs, rational rhs)  {   rational r ;
                                                    r.n = lhs.n/rhs.n ; r.d = lhs.d/rhs.d ;
                                                    return r ; }

int main()  {   cout <<'\n' <<"Let's create a rational number r..." <<'\n' <<'\n' ;

                cout <<"give me two ints(numerator and denominator) and i will creat the relative rational number" <<'\n' ;

                cout <<"give me the num: " ;
                int n1 ;
                cin >>n1 ;

                int d1 ;
                cout <<"give me the den: " ;
                cin >>d1 ;

                while(d1==0)    {   cout <<'\n' <<"0 is not a valid denominator..." <<'\n' ;
                                    cout <<"give me the den: " ;
                                    cin >>d1 ; }

                rational r(n1, d1) ;

                cout <<"the relative rational number is: " <<r.res <<'\n' ;
                cout <<"the minimal fraction is: " <<r.num() <<"/" <<r.den() <<'\n' <<'\n' ;

                rational a(5,2) ;

                cout <<"using the rational number a = 5/2 = " <<a.res <<"let's make some computations" <<'\n' <<'\n' ;

                cout <<"a+r= " <<(a+r).res <<'\n' <<'\n' ;

                cout <<"a*r= " <<(a*r).res <<'\n' <<'\n' ;

                cout <<"a/r =" <<(a/r).res <<'\n' <<'\n' ;

            }
