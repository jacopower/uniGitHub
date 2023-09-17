// vector

#include <iostream>
#include <cmath>
#include <vector>           // needed for vector

using std::cin ;
using std::cout ;
using std::vector ;

int main () {   cout <<'\n' <<"Let's learn a bit about vectors..." <<'\n' <<'\n' ;

                cout <<"i have a vector d = {2,1} equal to a vector f" <<'\n' <<'\n' ;

                vector<int> a ;                 // empty vector
                vector<int> b {2} ;             // one element, initialized to 2
                vector<int> c (2) ;             // two elements, auto-initialized to 0
                vector<int> d {2,1} ;           // two elements, initialized to 2 and 1
                vector<int> e (3,1) ;           // three elements, all initialized to 1
             // vector<int> f (2,1,8) ;         // error, max two arguments

                auto v =d ;

                cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' ;     // 2, 1, 0, 0

                v[1] =5 ;                       // sets the element number 1 to a value of 5

                v.push_back(-2) ;               // method that adds a num (-2) at the end of the vector (v is now {2,5,-2})

                cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' <<'\n' ;     // 2, 5, -2, 0

                cout <<"v size=" <<v.size() <<'\n' <<'\n' ;               // method that gives the number of elements of the vector  // 3
   }
