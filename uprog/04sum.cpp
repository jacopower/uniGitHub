// sum

#include <iostream>

int main () {	std::cout <<'\n' <<"I will sum two numbers..." <<'\n' <<'\n' <<"insert the firts number" <<'\n' ;
             	int number1 ;	// create an int type variable: some memory is needed for the int t called "number1"
            	std::cin >>number1 ;	// the imput defines the value of the int (initialize the int)
              	std::cout <<'\n' <<"insert the second number" <<'\n' ;
             	int number2 ;
             	std::cin >>number2 ;
              	int result= number1 + number2 ;	/* define and initialize an integer es the sum of two other integers 
															(the sum (+) is one of the possible operations with int) */
              	std::cout <<'\n' <<"the sum is: " <<result <<'\n' <<'\n' ;

            }
