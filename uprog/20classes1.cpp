// classes1

#include <iostream>
#include <string>

using std::cin ;
using std::cout ;
using std::string ;


class book1 {
   public:                                                     // creating a new type called book1
      string title ;
      string author ;
      int pages ;
      book1()  {  
         cout <<"creating object" <<'\n' ;         // constructor for 'book' class (same name as class's) = function executed when i create an objet of this class type
                                                   // no variable in () so when i create a new object i dont have to put '(...)' to execute the function 
         title="no title" ;
         author="no author" ;
         pages=0 ;
      }
   // int book1()  { ... }                            // error, int is invalid type for a constructor (no type needed)
} ;

class book2 {
   public:  string title ;
            string author ;
            int pages ;
            book2(string atitle, string aauthor, int apages)   {  
               title=atitle ;    // in () there are 3 vaiables, so when i create an objet of this type i need to put argments in ()
               author=aauthor ;
               pages=apages ; 
            }
} ;


int main()  {
   cout <<'\n' <<"Let's learn a bit about classes!" <<'\n' <<'\n' ;
                
   book1 b1 ;                                         // memory reserved for an object of type book (same as 'book book1()')
// book1 b = 3 ;                                // error, a book type object cant be initialize as 3 based on the type caratheristics (as i cant initialize an int as "r")
// book1 b ={"tit", "auth", "pg"}               // error, nonsense, is not an array
   
   b1.title ="harrypotter" ;                          // adressing and initializing the 'title' caratheristic of the book type object 'book1'
   b1.author ="jkrowling" ;
   b1.pages =400 ;
   b1.pages =500 ;
// book1.pages ="string" ;                      // error, the caratheristic 'pages' is int type
// cout <<b1 ;                                  // error, doesn't know what to print, there is more than 1 public info

   cout <<b1.title <<'\n' <<'\n';               // harrypotter

   book2 b2("lordofthering", "tolkien", 700) ;
   cout <<b2.pages <<'\n' <<'\n' ;              // 700

/* book2 b ;                                    // error, b needs arguments in the parentesis like "book2 b("a","b",0)"
                                                         or you need to add a constructor like "book2() {...}" */
}
