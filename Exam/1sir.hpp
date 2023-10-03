// 1sir.hpp

#ifndef SIR_HPP
#define SIR_HPP

#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

struct SIR  {   // allowes me to define the state of the infection in a specific day
    double S ;   // public
    double I ;
    double R ;
    double N ;
    int V ;
  } ;

class Pandemic  {   // allowes to create a SIR type object and define actions using it
      SIR SIR_0 ;  // private

    public:
      Pandemic(SIR const& initial_SIR) ;    // creates a pandemic type object

      std::vector<SIR> infection(double beta, double gamma, double T, bool vax) ;    // creates a vector and fills it with values of each parameter per day
  } ;

void CheckInput(double const& T,    // checks if user's imputs have valid arguments
                double const& N,
                double const& I,
                double const& beta,
                double const& gamma) ;

void Print(std::vector<SIR> const& SIRp) ;  // prints the grid containing the elements of the vector

void Intro() ;   // prints and intro

#endif
