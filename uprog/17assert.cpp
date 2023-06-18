// assert

#include <iostream>
#include <cassert>                          // needed for assert()

using std::cin ;
using std::cout ;
//using std::abort ;

int main() {    cout <<'\n' <<"Hi, give me some numbers and i will tell you which is the biggest..." <<'\n' <<'\n' ;

                cout <<"How many numbers do you want to write? " ;

                int n ;
                cin >>n ;

                assert(n>1) ;               // aborts if n>1 is not verified, prints on terminal "int main(): Assertion `n>1' failed. Aborted (core dumped)"
                                            // allowes only one argument
                //if (n==1) {abort() ;}     // does same as line above, but prints "Aborted (core dumped)""

                cout <<"insert the numbers:" <<'\n' ;

                int result =0 ;
                int a ;
                for (int i=0; i<n; ++i)    {    cin >>a ;
                                                if (a>result) { result=a ; }
                                                
                                            } ;

                cout <<'\n' <<"the biggest number is: " << result <<'\n' <<'\n' ;
                
            }
