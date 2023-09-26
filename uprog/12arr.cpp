// array

#include <iostream>

using std::cin ;
using std::cout ;

int main()  {  
   cout <<'\n' <<"Let's learn a bit about arrays..." <<'\n' <<'\n' ;
   
      int a0[5] ;                               // some memory space is needed for an array 5 int types elements, and call it a0
   // int a[] ;                           // error, storage size unknown
   /* a0[] ={1, 3, 91, 22, 64, 30} ;       // error, once i create the array i have to initialize the single components like a[n]=x
                                                         i can't initialize more components at once with ={} */

      int a1[] ={1, 5, 91, 22} ;                // a1 is an array containing ints and i initialized the first 4 (like saying int a1[4])
   // int a1[] ={1, , 91, 22} ;           // error, there are two consecutives ,
      a1[10] =100 ;                             // sets/changes the 10th element of the array a1 as 100

      int a2[1] ={7} ;
   // int a[0] ={7} ;                     //error, too many initializers for the storage set
   // int a[2] ={7, 8, 9} ;               //error, too many initializers for the storage set

      int a3[20] ={1, 5, 91, 22, 64, 30} ;      // equal to int a3[n] ={1, 3, 91, 22, 64, 30}  with n>=6
      a3[3] =66 ;                               // 66 is substituting 22
      a3[10] =100 ;
      a3[22] =200 ;

      cout <<'\n' ;
      cout <<"Hi, there are 4 arrays:" <<'\n' ;
      cout <<"int a0[5] ;  int a1[] ={1, 5, 91, 22} ;  int a2[1] ={7} ;  int a3[20] ={1, 5, 91, 22, 64, 30}" <<'\n' <<'\n';
      cout <<a0[4] <<", " <<a0[7] <<'\n' ;                     // random number, random number
      cout <<a1[0] <<", " <<a1[2] <<", " <<a1[10] <<'\n' ;     // 1, 91, 100
      cout <<a2[0] <<'\n' ;                                    // 7
      cout <<a3[2] <<", " <<a3[3] <<", " <<a3[4] <<", "<<a3[10] <<", " <<a3[22] <<'\n' ;     // 91, 66, 64, 100, 200
      cout <<'\n' ;

   cout <<"N.B :" <<'\n' <<"when you create an array, in the braces there is the actual number of elements it will contain (1 to infinity) ;" ;
   cout <<"when you call the array, in the braces there is the position of the element you are referring to (0 to infinity)" <<'\n' ;
   cout <<'\n' ;

      cout <<"now we have a two-dimentional array: int m0 [3][2] = {{1,2},{3,4},{5,6}}" <<'\n' <<'\n' ;
      
      int m0 [3][2] = {{1,4},{7,2},{3,0}} ;                                // 2d array (it is kind of a matrix to me)
      cout <<m0[0][1] <<", " <<m0[1][3] <<", " <<m0[3][1] <<'\n' <<'\n';   // 2, random number, random number
}
