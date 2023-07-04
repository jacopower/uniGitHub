// 1pandemic.cpp

#include "1pandemic.hpp"

Pandemic::Pandemic(SIR const& initial_SIR) : SIR_0{initial_SIR} {}

std::vector<SIR> Pandemic::infection(double beta, double gamma, int T, bool vax)    // the parameters are given from user
  {
    std::vector<SIR> result{SIR_0} ;

    double const N = SIR_0.S + SIR_0.I + SIR_0.R ;
    bool vstart = false ;

    assert(!result.empty()) ;    // checks if 'result' is not empty (abort if empty)

    for (int i = 1; i < T; ++i) {   // looping once a day
        SIR last_SIR = result.back() ;
        double S_last = last_SIR.S ;
        double I_last = last_SIR.I ;

        if (I_last / N > 0.3) vstart = true ;

        if (I_last == 1)  {
            last_SIR.S = round(S_last - beta * S_last * I_last / N) ;
            last_SIR.I = 0 ;
            last_SIR.R = N - last_SIR.S ;
          } 
        else  {
            last_SIR.S = round(S_last - beta * S_last * I_last / N) ;
            last_SIR.I = round(I_last + beta * S_last * I_last / N - gamma * I_last) ;

            if (last_SIR.S + last_SIR.I > N)  { last_SIR.I -= 1 ; }

            last_SIR.R = N - (last_SIR.S + last_SIR.I) ;

            assert(last_SIR.S >= 0 && last_SIR.I >= 0 && last_SIR.R >= 0) ;

            if (vax == true && vstart == true && last_SIR.S > ceil(N / 100))  {  // vaccination
                last_SIR.R += ceil(N / 100) ;
                last_SIR.S -= ceil(N / 100) ;
                last_SIR.V += ceil(N / 100) ;
              } 
            else if (vax == true && vstart == true && 
                    last_SIR.S <= ceil(N / 100) && last_SIR.S > 0) 
                    {
                      last_SIR.R += 1 ;
                      last_SIR.S -= 1 ;
                      last_SIR.V += 1 ;
                    }
          }
        assert(last_SIR.S + last_SIR.I + last_SIR.R == N) ;

        result.push_back(last_SIR) ; // at the end of the loop, 'result' contains T SIR type object, in chronological order
    }

    return result ;
  }

void CheckInput(double& t,
                int& T,
                double& N,
                double const& I,
                double const& beta,
                double const& gamma)
  {
    if (!std::cin.good()) {
      throw std::invalid_argument("The given input contains one or more errors") ;    // there will be a try block and a catch block in the main
    }
    if (N < 0) {
      N = -N ;
      std::cerr << "N° of people (N) has been converted to positive" << '\n' ;
    }
    if (floor(N) != ceil(N)) {
      throw std::invalid_argument("N° of people (N) must be a positive integer") ;
    }
    if (floor(I) != ceil(I)) {
      throw std::invalid_argument(
          "N° of infecteds (I) must be a positive integer") ;
    }
    if (I < 0 || I > N) {
      throw std::invalid_argument(
          "N° of infecteds (I) must be positive and smaller "
          "than N° of people (N)") ;
    }
    if (beta < 0 || beta > 1) {
      throw std::invalid_argument(
          "Beta must be a double greater than 0 and smaller than 1") ;
    }
    if (gamma < 0 || gamma > 1) {
      throw std::invalid_argument(
          "Gamma must be a double greater than 0 and smaller than 1") ;
    }
    if (t < 0) {
      t = -t ;
      std::cerr << "Time (T) has been converted to positive" << '\n' ;
    }
    if (floor(t) != ceil(t)) {
      std::cerr << "The variable time has been converted to " << floor(t) << '\n' ;
    }
    T = floor(t) ;
  }

void Print(std::vector<SIR> const& SIRp)
{
  int day = 0 ;

  std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+\n"
               "|     D     |     S     |     I     |     R     |     N     |     V     |\n"
               "+-----------+-----------+-----------+-----------+-----------+-----------+\n"
            << std::fixed ;
  for (auto& sir : SIRp) {
      ++day ;
      std::cout << "| " << std::setw(9) << day << " | "   // setw(n) sets the with of the following output/input to n char (fills fith spaces the remaning chars)
                << std::setw(9) << static_cast<int>(sir.S) << " | "   // 9 char (sir.s + spaces = 9) + ' | '
                << std::setw(9) << static_cast<int>(sir.I) << " | "
                << std::setw(9) << static_cast<int>(sir.R) << " | "
                << std::setw(9) << static_cast<int>(sir.S + sir.I + sir.R)
                << " | " << std::setw(9) << sir.V << " |\n" ;
  }
  std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+"
               "\n" ;
}

void Launch()
  {
    std::cout << std::string(50, '\n') ;
    std::cout << "+-----------------------------------------------------------------------+\n"
              << "|"
              << std::string(26, ' ') << "PANDEMIC SIMULATION"
              << std::string(26, ' ') << "|"
              << "\n"
                 "+-----------------------------------------------------------------------+\n\n" ;
    std::cout << "If you wish to abort, at any time, please press Ctrl+C on your Keyboard\n\n"
                 "+-----------------------------------------------------------------------+\n\n"
                 "If you wish to continue with the simulation, please answer the following questions:\n\n" ;
  }
