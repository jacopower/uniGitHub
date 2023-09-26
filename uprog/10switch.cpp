// switch

#include <iostream>
#include <string>

using std::cin ;
using std::cout ;
using std::string ;

int main()  {
    cout <<'\n' <<"A good alternative to a if/else chain is the command switch..." <<'\n' ;

    cout <<"for example in ese5.cpp it is used to set an action in response to any char you chose..." <<'\n' <<'\n' ;

    cout <<"choose a vowel: " ;
    char a ;
    cin >>a ;

    switch(a)   {   case 'a':       cout <<"alpaca" ;          // used when one object can be multiple things (true/false ,a number, a letter, a word, ...)
                                break ;                     // and you can switch between the options of being of the object
                    case 'e':       cout <<"eagle" ;
                                break ;
                    case 'i':       cout <<"iguana" ;
                                break ;
                    case 'o':       cout <<"orangotangus" ;
                                break ;
                    case 'u':       cout <<"urial" ;
                                break ;
                    default:        cout <<"that's not a vowel" ;
                                break ;
                }

    cout <<'\n' <<'\n' ;

    cout <<"otherwise one other valid substitute ti one if/else statement is the conditional statement, as it follows..." <<'\n' ;
    cout <<"condition ? truestat : falsestat ... for example" <<'\n' <<'\n';

    cout <<"how old are you? " ;
    int e ;
    cin >>e ;

    string r ;
    r = (e==21) ? "me too!!!" : "okay, you old af" ;

    cout <<'\n' <<r <<'\n' <<'\n' ;
}
