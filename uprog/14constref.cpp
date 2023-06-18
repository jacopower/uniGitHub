// constref

#include <iostream>

using std::cin ;
using std::cout ;
using std::string ;

int main () {   cout <<"Let's learn about references and constants!" <<'\n' ;
                cout <<"let's start with i=12 and j=56..." <<'\n' <<'\n' ;
                int i =12 ;
                int j =56 ;

                int& ri =i ;
             // int& r ;                                // error, a reference must be initialized to refer to a valid object
             // int& r =2 ;                             // error, cant't refer to a value like this but to an object

                cout << ri ;                                            // 12

                ri =34 ;
                cout <<"i=" <<i <<", ri=" <<ri <<'\n' ;                 // 34, 34

                ri =j ;
                cout <<"i=" <<i <<", ri=" <<ri <<'\n';                  // 56, 56

                i =4 ;
                cout <<"i=" <<i <<", ri=" <<ri <<'\n' <<'\n' ;          // 4, 4
                
             // when you modify either the original object or the reference you will modify both

                int const& cri = i ;

                i=5 ;
                cout <<"i=" <<i <<", ri=" <<ri <<", cri=" <<cri <<'\n' <<'\n' ;          // 5, 5

             // cri =6 ;                                // error, you can't modify a const object

                cout <<"then if i set cs=hello..." <<'\n' <<'\n' ;
                
                string const cs ="hello" ;
             // cs ="hi" ;                              // error, you can't modify a const object

                string const& rcs = cs ;
             // string& rcs =cs ;                       // error, cs is const so rcs must be const (or you could modify cs via rcs for reference type properties)

                cout <<"cs= " <<cs <<", rcs=" <<rcs <<'\n' <<'\n' ;     // hello, hello
            }
