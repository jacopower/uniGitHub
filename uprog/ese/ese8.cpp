// ese8

#include <iostream>

using std::cin ;
using std::cout ;
using std::abort ;

double compute(double n1, double n2, char op)  {   double result =0 ;
                                                    switch(op)  {   case '+' : result = n1+n2 ;
                                                                                break ;
                                                                    case '-' : result = n1-n2 ;
                                                                                break ;
                                                                    case '*' : result = n1*n2 ;
                                                                                break ;
                                                                    case '/' : try  {   if(n2==0) {throw n2 ; }
                                                                                        result = n1/n2 ;
                                                                                    }
                                                                               catch(double er) { cout <<'\n' <<"exception: denominator is 0" <<'\n' ; } 
                                                                                break ;

                                                                    default : try { throw op ; }
                                                                              catch(char pp) { cout <<'\n' <<"exception: invalid operator " <<'\n'; } ;
                                                                                break ;
                                                                }
                                                    return result ;
                                                }

int main()  {   cout <<'\n' <<"Hi, let's have some fun..." <<'\n' <<'\n' ;

                cout <<"give me two numbers and one operator: " <<'\n' ;

                cout <<"n1: " ;
                double n1 ;
                cin >>n1 ;
                
                cout <<"n2: " ;
                double n2 ;
                cin >>n2 ;

                cout <<"op: " ;
                char op ;
                cin >>op ;
                
                auto result =compute(n1, n2, op) ;

                cout <<"the result of the computation is: " <<result <<'\n' <<'\n' ;
            }