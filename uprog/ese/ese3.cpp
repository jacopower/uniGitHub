// ese3

#include <iostream>
#include <string>

using namespace std ;

int pow(int base, int exp)  {   int result=1 ;
                                for (int i =0; i<exp; ++i) { result *=base ; }

                                return result ;
                            }

int gcd(int n1, int n2) {   int result=1 ; 
                            int i =1 ;
                            
                            if(n1>n2)   {   for(; i<=n2; ++i)   {   int rest1 =n1%i ;
                                                                    int rest2 =n2%i ;
                                                                    if((rest1==0)&&(rest2==0)) { result =i ; }
                                                                }
                                        }
                                else    {   for(; i<=n1; ++i)   {   int rest1 =n1%i ;
                                                                    int rest2 =n2%i ;
                                                                    if((rest1==0)&&(rest2==0)) { result =i ; }
                                                                }
                                        }

                            return result ;
                        }

int lcm(int n1, int n2) {   int result ;
                            int i =1 ;
                            int j =n1*n2 ;

                            if(n1>n2)   {   
                                            int m =n1*i ;
                                            int rest2 =m%n2 ;

                                            for(; j>=n1; --j)   {   int rest1 =j%n1 ;
                                                                    int rest2 =j%n2 ;
                                                                    if((rest1==0)&&(rest2==0)) { result =j ; } 
                                                                }
                                            
                                            /*
                                            bool b =0 ;
                                            for(; b=1; ++i)     {   int m =n1*i ;
                                                                    int rest2 =m%n2 ;
                                                                    if(rest2==0) { result=m ;}
                                                                    b = (rest2==0) ;
                                                                }
                                            */
                                                             
                                        }
                                else    {   for(; j>=n2; --j)   {   int rest1 =j%n1 ;
                                                                    int rest2 =j%n2 ;
                                                                    if((rest1==0)&&(rest2==0)) { result =j ;}
                                                                }
                                            
                                            /*
                                            bool b =0 ;
                                            for(; b=1; ++i)     {   int m =n2*i ;
                                                                    int rest1 =m%n1 ;
                                                                    if(rest1==0) { result=m ;}
                                                                    b = (rest1==0) ;
                                                                }
                                            */

                                        }
                            
                            return result ;
                        }

string is_prime(int prime)  {   int i =1 ;
                                int md ;

                                while(i<prime)  {   int rest =prime%i ;
                                                    if(rest==0) { md=i ; }
                                                    ++i ;
                                                }

                                string result ;
                                if(md==1)   { result ="is prime" ; }
                                    else    { result ="is not prime" ; }
                        
                                return result ;
                            }


int main() {    cout <<'\n' <<"Hi," <<'\n' <<'\n' ;

                cout <<"give me two numbers: the base and the exponent..." <<'\n' ;                
                cout <<"base: " ;
                int base ;
                cin >> base ;
                cout <<"exponent: " ;
                int exponent ;
                cin >> exponent ;
                int power =pow(base, exponent) ;
                cout <<"That's the power: " <<power <<'\n' <<'\n' ;

                cout <<"give me two numbers, i will tell you the greatest common divisor..." <<'\n' ;
                cout << "n1: " ;
                int n1 ;
                cin >>n1 ;
                cout <<"n2: " ;
                int n2 ;
                cin >>n2 ;
                int mcd =gcd(n1, n2) ;
                cout <<"that's the gcd: " <<mcd <<'\n' <<'\n' ;

                cout <<"give me two numbers, i will tell you the least common multiple..." <<'\n' ;
                cout <<"n1: " ;
                int first ;
                cin >>first ;
                cout <<"n2: " ;
                int second ;
                cin >>second ;
                int mcm =lcm(first, second) ;
                cout <<"the lcm is: " <<mcm <<'\n' <<'\n' ;

                cout <<"give me one number and i will tell you if it is prime..." <<'\n' ;
                cout <<"write: " ;
                int prime_number ;
                cin >>prime_number ;
                string prime_result =is_prime(prime_number) ;
                cout <<prime_number <<" " <<prime_result <<'\n' <<'\n' ;

            }
