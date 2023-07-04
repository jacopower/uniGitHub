// 1main.cpp

#include "1pandemic.hpp"

int main() {

double N = 0 ;
double S = 0 ;
double I = 0 ;
double R = 0 ;
double beta = 0 ;
double gamma = 0 ;
double t = 0 ;
int T = 0 ;
int V = 0 ;
bool vax = false ;
char v = 'n' ;

    Launch() ;

    try {
          std::cout << "VACCINATION:\n"
                      "If more than 30% of the populatione is infected, "
                      "do you want to start to vaccinate? (y/n)"
                    << '\n' <<'\n' ;
          std::cin >> v ;

          switch(v) {
                      case 'y': vax = true ;  // later used to initiate vaccination
                                break ;
                      case 'n':
                                break ;
                      default:  throw std::invalid_argument("The answer must be y (yes) or n (no)") ;
                    }

          std::cout << '\n' <<  "Please input N° of days, N° of people, N° of infecteds, "
                                "probability of infection and probability of recovery"
                    << '\n' <<'\n' ;
          std::cin >> t >> N >> I >> beta >> gamma ;    // the user chooses the initial parameters
          std::cout << '\n' ;

          CheckInput(t, T, N, I, beta, gamma) ;   // checks if user's imputs have valid arguments

          S = N - I ;

          SIR sir0{S, I, R, V} ;
          Pandemic pandemi4{sir0} ;

          std::vector<SIR> const tdata = pandemi4.infection(beta, gamma, T, vax) ;    // vector containing the values of each parameter per day

          Print(tdata) ;    // prints the grid containing the values of each parameter per day
        } 
    catch(std::invalid_argument const& e) { std::cerr << e.what() << '\n' ; }   // ?
  }
