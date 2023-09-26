// ese2

#include <iostream>
using namespace std ;

int main() {   cout <<'\n' <<"Hi, give me some numbers and i will tell you which is the biggest..." <<'\n' <<'\n' ;

                cout <<"How many numbers do you want to write? " ;

                int n ;
                cin >>n ;
                while (n==1)    {   cout <<"dumbass, give me more" <<'\n' <<"How many numbers do you want to write? " ;
                                    cin >>n ;
                                }
                
                cout <<"insert the numbers:" <<'\n' ;

                int result =0 ;
                int a ;
                for (int i=0; i<n; ++i)    {   cin >>a ;
                                                if (a>result) { result=a ; }
                                                
                                            }

                cout <<'\n' <<"the biggest number is: " << result <<'\n' <<'\n' ;
                
            }
