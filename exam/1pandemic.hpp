// 1pandemic.hpp

#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP

#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

struct SIR  {
    double S ;   // public
    double I ;
    double R ;
    int V ;
  } ;

class Pandemic  {
      SIR SIR_0 ;  // private

    public:
      Pandemic(SIR const& initial_SIR) ;

      std::vector<SIR> infection(double beta, double gamma, int T, bool vax) ;    // could have i used a nested class?
  } ;

void CheckInput(double& t,
                int& T,
                double& N,
                double const& I,
                double const& beta,
                double const& gamma) ;

void Print(std::vector<SIR> const& SIRp) ;

void Launch() ;

#endif
