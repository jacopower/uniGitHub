// if

#include <iostream>

int main () {
        std::cout <<'\n' <<"Let's learn to use the if/else chain..." <<'\n' <<'\n' ;

        std::cout <<"I will tell you which number is the smallest" <<'\n' <<'\n';

        std::cout <<"insert the first number" <<'\n' ;
        int n1 ;
        std::cin >>n1 ;

        std::cout <<'\n' <<"ok, now insert the seocnd number" <<'\n';
        int n2 ;
        std::cin >>n2 ;

        int result ; /* se definisco int result nell'if o nell'else allora lo devo stampare prima d chiudere la graffa,
                        mi conviene definirlo prima (una sola volta) e stamparlo dopo (una sola volta) */

        if ( n1<n2 )    { result= n1 ; } // se n1<n2 , int result=n1
                else    { result= n2 ; } // se n1>n2 , int result=n2
                
        std::cout <<'\n' <<"The smallest number is: " <<result <<'\n' <<'\n' ;
}
