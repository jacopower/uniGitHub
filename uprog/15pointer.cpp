// pointer

#include <iostream>

using std::cin ;
using std::cout ;
using std::string ;

int main()  {   cout <<'\n' <<"Let's learn a bit about pointers!" <<'\n' <<'\n' ;

                cout <<"we have four objects: int i =19 ; double d =5.3 ; string s ='luca'; int intero =8" <<'\n' ;
                int i =19 ;
                double d =5.3 ;
                string s ="luca" ;

                cout <<"memory location of the object 'age': " <<&i <<'\n' <<'\n' ;     // &age is a pointer (=memory adress of the object 'i')

             // &i =65 ;                    // error, can't change the memory adress
             // &i = &d ;                   // error, same

                int *pi =&i ;                                                           // *pi is a pointer (pi is the memory adress, *pi is the content of the memory adress 'pi')
             // int *pi =4 ;                // error, a pointer must be initialized with a valid memory location (4 is a constant int, not a pointer)
                double *pd =&d ;
                string *ps =&s ;

                cout <<pd <<" = " <<&d <<" = " <<&*&d <<'\n' <<'\n' ;                     // &d 
                cout <<d <<" = " <<*pd <<" = " <<*&d <<" = " <<*&*&d <<'\n' <<'\n' ;      // &d, 5.3
             // cout <<&&d ;                // error, &&d is the memory adress of &d, wich is a mem adress so in not a valid type
             // cout <<**d ;                // error, **d is the content of the mem adress *pi, wich is not a mem adress so is not a valid type


                *ps ="michele" ;                                                        // same as s="michele"
                cout << ps <<", " <<*ps <<'\n' <<'\n' ;                                 // &s, michele

                int intero =8 ;
                int *guagliu =&intero ;
                cout << guagliu <<", " <<*guagliu <<'\n' <<'\n' ;                       // &intero, 8
            }
