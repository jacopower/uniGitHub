// exceptions2

#include <iostream>

using std::cin ;
using std::cout ;
using std::runtime_error ;

int gcd(int,int) ;

class rational  {
    private:

    public:
        int n ;
        int d ;

        int num() { if(d>0) return n/gcd(n,d) ;
                    else return -n/gcd(n,d) ; }
        int den() { return abs(d)/gcd(n,d) ; }

        double res = n/d ;

        rational()  { n=1; d=1 ; }
        rational(int an, int ad) {
            n=an ; d=ad ; 
            if (d==0) { throw d ; } ; // throw block
        }
} ;

int main()  {
    cout <<'\n' <<"Let's learn a bit about exceptions..." <<'\n' ;
    cout <<"i will use one of my last programs: ese7" <<'\n' <<'\n' ;
    cout <<"give me two ints(numerator and denominator) and i will creat the relative rational number" <<'\n' ;

    cout <<"give me the num: " ;
    int n1 ;
    cin >>n1 ;

    int d1 ;
    cout <<"give me the den: " ;
    cin >>d1 ;

    rational r ;

    try {r = {n1, d1,} ; }                                          // try block (containing a throw block in the definition of r)
    catch(runtime_error e) { cout <<'\n' <<"exceprion cant divide by zero" <<e.what() <<'\n' ; }    // catch block

    cout <<"the relative rational number is: " <<r.res <<'\n' ;
    cout <<"the minimal fraction is: " <<r.num() <<"/" <<r.den() <<'\n' <<'\n' ;

    rational a(5,2) ;

    cout <<"using the rational number a = 5/2 = " <<a.res <<"let's make some computations" <<'\n' <<'\n' ;

    return 0 ;
}

int gcd(int n1, int n2) {
    int result=1 ; 
    int i =1 ;
    int an1 =abs(n1) ;
    int an2 =abs(n2) ;
    
    if(an1>an2) {   for(; i<=an2; ++i)  {int rest1 =an1%i ;
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
