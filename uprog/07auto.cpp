// auto

#include <iostream>
#include <string>

struct complex {    double r ;
                    double i ;  
} ;
                
complex c0={1,2} ;

int main()  {
    std::cout <<'\n' <<"Let's learn a bit about 'auto'..." <<'\n' <<'\n' ;
    std::cout <<'\n' <<"'auto' allows to set automatically the type of an object" <<'\n' <<'\n' ;
    
    // auto z ;                                // error, no initializer
    auto i =0 ;                             // int
    auto d=0.4 ;                            // double
    auto const f=0.F ;                      // float const
    auto r =i+f ;                           // float
    auto c1 = c0 ;                          // complex
    auto& rc =c1 ;                          // complex&
    auto const& cri =i ;                    // int const&
    auto& g =f ;                            // float const& (the constness is preserved from f, because g is a rerference)
    auto j =cri ;                           // int (auto never preserves a reference. and the constness is not preserved because is not referencing to cri, is just setting j)
    auto& rcr =c1.r ;                       // double& (c.r is double)
    auto c ='h' ;                           // char
    auto s ="ciao" ;                        // string

    std::cout <<"To see the text write in the terminal: cat auto.cpp" <<'\n' <<'\n' ;
}
