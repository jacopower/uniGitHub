// constref

#include <iostream>
#include <string>

using std::cin ;
using std::cout ;
using std::string ;

int main () {
   cout <<"Let's learn about references and constants!" <<'\n' ;

      cout <<"let's start with i=12 and const j=56..." <<'\n' <<'\n' ;
      int i =12 ;
      int const j =56 ;

   // j =57                    // error, i cant modify a const object

      int& ri =i ;
   // int& r ;                  // error, a reference must be initialized to refer to a valid object
      // int& r =2 ;               // error, must refer to an object, cant't refer to a value like this 

      cout <<"ri = " <<ri ;                                            // 12

      cout <<"if i set i=4..." <<'\n' <<'\n' ;
      i =4 ;
      cout <<"i=" <<i <<", ri=" <<ri <<'\n' <<'\n' ;          // 4, 4

      cout <<"if ri=34..." <<'\n' <<'\n' ;
      ri =34 ;
      cout <<"i=" <<i <<", ri=" <<ri <<'\n' ;                 // 34, 34

      cout <<"if ri=j..." <<'\n' <<'\n' ;                          // 12
      ri =j ;
      cout <<"i=" <<i <<", ri=" <<ri <<'\n' <<'\n' ;                  // 56, 56

   cout <<"if you create a reference, you will modify both if you modify either the original object or the ref" <<'\n' <<'\n' ;

      cout <<"if i set cri=i..." <<'\n' <<'\n' ;
      int const& cri = i ;
      cout <<"cri = " <<cri ;                                            // 56

      cout <<"if i=5..." <<'\n' <<'\n' ;                          // 12
      i=5 ;
      cout <<"i=" <<i <<", ri=" <<ri <<", cri=" <<cri <<'\n' <<'\n' ;          // 5, 5

      // cri =6 ;                                // error, you can't modify a const object

      cout <<"you can modify the original object only by modifying it directly or it references (not const ref)" <<'\n' <<'\n' ;

      cout <<"then if i set cs=hello..." <<'\n' <<'\n' ;
      
      string const cs ="hello" ;
   // cs ="hi" ;                              // error, you can't modify a const object

      string const& rcs = cs ;
   // string& rcs =cs ;                       // error, cs is const so rcs must be const (or you could modify cs via rcs for reference type properties)

      cout <<"cs= " <<cs <<", rcs=" <<rcs <<'\n' <<'\n' ;     // hello, hello
}
