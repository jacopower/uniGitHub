// DMA

#include <iostream>

using std::cin ;
using std::cout ;

int main()  {
    cout <<'\n' <<"Let's learn a bit about Dinamic Memory Allocation (DMA)!" <<'\n' <<'\n' ;
    cout <<"DMA allows you to set array size dynamically during run time, rather than in compile time." <<'\n' ;
    cout <<"DMA means using a pointer to an unnamed 'new *type*' variable," <<'\n'
            <<"the keyword 'new' allows to allocate objects in heap memory (the pointer is in stack memory)" <<'\n' <<'\n' ;

        cout <<"enter the size of the array i will create: " ;
        int size ;
        cin >>size ;

        int* ap = new int [size] ;      // ap in in stack memory, unnamed 'new *type*' is in heap memory

        cout <<"enter the values to be stored in the array: " <<'\n' ;
        for (int i=0; i<size; ++i) {
            cin >> ap[i] ;
        }

        cout <<"the array contains: " ;
        for (int i=0; i<size; ++i) {
            cout << ap[i] <<", " ;
        }
        cout <<'\n' <<'\n' ;

        delete [] ap ;  // [] are needed because ap points to an array (if was a simple int, no braces needed)
    cout <<"'delete [] ap' is not deleting the pointer itself (it is statically allocated so it will be deleted when i finish to use the program), "
            <<"but is freeing the memory it is pointing to (to prevent creating garbage memory we can't use or free) " <<'\n' ;
    cout <<"Deleting ap eventually makes the pointer point to nothing (ap = NULL)" <<'\n' <<'\n' ;
}
