// while

#include <iostream>

int main () {   std::cout <<'\n' <<"Hi, give me an integer and i will tell you its square root (approximately... ;-)) " <<'\n' <<'\n' ;
                std::cout <<"write: " ;

                int n ;
                std::cin >>n ;

                int i =0 ;
                while (i*i <n)  { ++i ; }   /* untill i*i<n keep doing the {statement}:
                                                i*i<n ? if yes, i=i+1 and ask again; if no, stop and exit the while */
                
                std::cout <<'\n' <<"the answer is: " <<i <<'\n' <<'\n' ;

            }
