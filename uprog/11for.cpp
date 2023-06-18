// for

#include <iostream>

int main () {   std::cout <<'\n' <<"Hi, give me a number and i will sum all the previous one..." <<'\n' <<'\n' ;
                std::cout <<"write: " ;

                int n ;
                std::cin >>n ;
                
                int sum =0 ;
                for (int i =1 ; i <=n ; ++i) {  sum +=i ; } /* execute initial statement (int i=1); check if condition is true (i<=n); 
                                                                if yes, do statement {sum=sum+i} and do expression (++i) untill the condition in false;
                                                                if no, exit stop and the if */

                std::cout <<'\n' <<"the sum is: " <<sum <<'\n' <<'\n' ;

            }
