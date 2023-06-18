// vector

#include <iostream>
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

//

                vector<int>::iterator first =v.begin() ;          // 'first' must be the same type as v.begin() = vector<int>::iterator type
                                                                  // v.begin() is a method that points to the first element of vector v
                int last = *v.end() ;                             // pointer to an iterator that points to one past the last element of the vector v
             // i can use an iterator when i have a range (vector or string are ranges) by accessing it with the dot (range.iterator) or arrow (*range->iterator)

             // cout <<first ;                  // error, the content of first must be passed as a pointer (because, as an iterator, has no value but has a content )
                cout <<"first=" <<*first <<", last=" <<last ;       // 2, 7

             // first = 3 ;                     // error, first in as iterator type, i cant change the value of its content this way...
                v[0] = 3 ;                      // ...but i can this way (v is now {3,5,-2})
                cout <<", new first=" <<*first <<'\n' <<'\n' ;         // 3
             
             // 'first' is the first container of information of v, not the value contained in it, so i can change the value and 'first' will point to it anyways


                auto second = v.begin()+1 ;
                
                cout <<"(it)second=first = " << (first==second) <<'\n' ;       // 0
                ++first ;                          // now it points to the next element
                cout <<"(it)second=++first = " << (first==second) <<'\n' ;       // 1

                --first ;
                cout <<"first+2=third=" <<*(first+2) ;       //-2

                first +=2 ;
                cout <<" = " <<*first <<'\n' <<'\n' ;         // -2

                v.erase(first) ;
                cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' ;     //

                v.erase(second, v.end()) ;
                cout <<"v[0]=" <<v[0] <<", v[1]=" <<v[1] <<", v[2]=" <<v[2] <<", v[3]=" <<v[3] <<'\n' <<'\n' ;     //

            }
