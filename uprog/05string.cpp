// string

#include <iostream>
#include <string>       // even if string is contained in iostream, it may not be in the future, so don't count on that

using std::cin ;
using std::cout ;
using std::string ; // string type (actually contained in std namespace)

int main()  {
    cout <<'\n' <<"Let's learn a bit about strings..." <<'\n' <<'\n' ;
    cout <<"A string is a series of characters" <<'\n' <<'\n' ; 

    char c ='A' ;   // this is a single character
    cout <<"an example of char is: " <<c <<'\n' <<'\n' ;

    // char c_ = 'ciao' ;  // error

    string s ="this is a string" ;  //this is a series of characters
    cout <<"an example of string is: " <<s <<'\n' <<'\n' ;

    cout <<"the lenght of the string is: " <<s.length() <<'\n' <<'\n' ;

    cout <<"this is the letter n^ 0 of the string: " <<s[0] <<'\n' ;   // the first letter is the number 0
    cout <<"this is the letter n^ 5 of the string: " <<s[5] <<'\n' ;
    cout <<"this is the letter n^ 7 of the string: " <<s[7] <<'\n' <<'\n' ;

    s[0] ='P' ; // initialize (changes) the n-th letter
    cout <<"this is the string after i modified the letter number 0: " <<s <<'\n' <<'\n' ;

    cout <<"position of the string 'tri': " <<s.find("tri", 0) <<'\n' ;  // looks for the presence of the char/string starting from the letter 0
    cout <<"position of the string 'is': " <<s.find("is", 0) <<'\n' <<'\n' ;  // looks for the presence of the char/string starting from the letter 0

    cout <<"this is a substring: " <<s.substr(8,5) <<'\n' <<'\n' ; //takes a substring of a string starting from digit 8 and is long 5 digits

    cout <<"give me a string: " ;
    string s1 ;
    getline (cin, s1) ; // cin >>s1 ;
    cout <<"nice!" <<'\n';

}
