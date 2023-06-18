// even

#include <iostream>

int main() {    std::cout <<'\n' <<"Give me a number and i will tell you if it is even" <<'\n' <<'\n';
                std::cout <<"write: " ;

                int n ;
                std::cin >> n ;

                int r =n%2 ;    // r = n%2 = rest of n/2
                bool result ;   /* result is an object that can be 1 or 0 (true or false)
                                    (bool object seems kinda useless)*/
                result = r==0 ; // the value of result depends on the statemant "r==0"

                std::cout <<'\n' ;
                std::cout <<std::boolalpha <<result ; // print result in the form of true/false, not 1/0 (without boolalpha)
                std::cout <<'\n' <<'\n' ;

            }


/* 
int main() {    std::cout <<'\n' <<"Give me a number and i will tell you if it is even" <<'\n' <<'\n';
                std::cout <<"write: " ;

                int n ;
                std::cin >> n ;

                int r =n%2 ;

                std::cout <<'\n' ;
                if (r==0)   { cout <<"Yes, it is even" ; }
                    else    { cout <<"No, it is not even" ; }
                std::cout <<'\n' <<'\n' ;

            }
*/
