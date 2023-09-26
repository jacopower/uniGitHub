// iterator

#include <iostream>
#include <cmath>
#include <vector>           // needed for vector

using std::cin ;
using std::cout ;
using std::vector ;

int main () {
   cout <<'\n' <<"Let's learn a bit about iterators..." <<'\n' <<'\n' ;

      vector<int> v {2,1,-2} ;

      vector<int>::iterator first =v.begin() ;          // 'first' must be the same type as v.begin() = vector<int>::iterator type
                                                      // v.begin() is a method that points to the first element of vector v
      int last = *v.end() ;                             // pointer to an iterator that points to one past the last element of the vector v
      cout <<"i can use an iterator when i have a range (vector or string are ranges) by accessing it with the dot (range.iterator) or arrow (*range->iterator)" <<'\n' <<'\n' ;

   // cout <<first ;                  // error, the content of first must be passed as a pointer (because, as an iterator, has no value but has a content )
      cout <<"first=" <<*first <<", last=" <<last ;       // 2, 7

   // first = 3 ;                     // error, first in as iterator type, i cant change the value of its content this way...
      v[0] = 3 ;                      // ...but i can this way (v is now {3,5,-2})
      cout <<", new first=" <<*first <<'\n' <<'\n' ;         // 3
   
   cout <<"the iterator 'first' is the first container of information of v, not the value contained in it, so i can change the value and 'first' will point to it anyways" <<'\n' <<'\n' ;


      auto second = v.begin()+1 ;
      cout <<"second = " <<*second <<'\n' ;
      
      cout <<"second == first = " << (first==second) <<'\n' ;       // 0
      ++first ;                          // now it points to the next element
      cout <<"second == ++first = " << (first==second) <<'\n' ;       // 1

      --first ;
      cout <<"first+2 == third =" <<*(first+2) ;       //-2

      first +=2 ;
      cout <<" = " <<*first <<'\n' <<'\n' ;         // -2

      auto mid = v.begin() + floor(v.size()/2) ;
      v.insert(second, 42) ; //idk
      cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' <<'\n' ;     //
      cout <<"v size=" <<v.size() <<'\n' <<'\n' ;               //

      v.erase(first) ; // idk
      cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' ;     //
      cout <<"v size=" <<v.size() <<'\n' <<'\n' ;               //

      v.erase(second, v.end()) ; //idk
      cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' <<'\n' ;     //
      cout <<"v size=" <<v.size() <<'\n' <<'\n' ;               //
}
