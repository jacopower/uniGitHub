// 1main.cpp

#include "1sir.hpp"

int main() {

double t = 0 ;    // tot days given by user
double T = 0 ;       // tot days
double N = 0 ;    // tot number of people
double S = 0 ;       // suscettible
double I = 0 ;    // infected
double R = 0 ;       // recovered
double beta = 0 ; // prob of infection
double gamma = 0 ;// prob of recovery
bool vax = false ;// will to vaccinate
char v = 'n' ;
double V = 0 ;       // tot number of vaxed people

    Intro() ;

    try {
          std::cout << '\n' <<  "Please input N° of days, N° of people, N° of infecteds, "
                                "probability of infection and probability of recovery"
                    << '\n' <<'\n' ;
          std::cin >> t >> N >> I >> beta >> gamma ;    // the user chooses the initial parameters
          std::cout << '\n' ;

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
                      default:  throw std::invalid_argument("The answer must be 'y' (yes) or 'n' (no)") ;
                    }

          CheckInput(t, T, N, I, beta, gamma) ;   // checks if user's imputs have valid arguments

          S = N - I ;   // initial suscettible

          SIR sir0{S, I, R, S+I+R, V} ;
          Pandemic COVID{sir0} ;

          std::vector<SIR> const totdata = COVID.infection(beta, gamma, T, vax) ;    // vector containing the values of each parameter per day

          Print(totdata) ;    // prints the grid containing the values of each parameter per day
        } 
    catch(std::invalid_argument const& e) { std::cerr << e.what() << '\n' ; }   // ?
  }
