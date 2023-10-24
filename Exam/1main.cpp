// 1main.cpp

#include "1sir.hpp"

int main() {

  double t = 0;     // tot days
  double n = 0;     // tot number of people
  double i = 0;     // infected
  double r = 0;     // recovered
  double beta = 0;  // prob of infection
  double gamma = 0; // prob of recovery
  bool vax = false; // will to vaccinate
  char v = 'n';

  Intro();

  try {
    std::cout << '\n'
              << "Please input: N° of days, N° of people, N° of infecteds, "
                 "probability of infection and probability of recovery"
              << '\n';
    std::cin >> t >> n >> i >> beta >>
        gamma; // the user chooses the initial parameters
    std::cout << '\n';

    CheckInput(t, n, i, beta,
               gamma); // checks if user's imputs have valid arguments

    std::cout << "VACCINATION:\n"
                 "If more than 30% of the populatione is infected, "
                 "do you want to start to vaccinate? (y/n)"
              << '\n';
    std::cin >> v;
    std::cout << '\n';

    switch (v) {
    case 'y':
      vax = true; // later used to initiate vaccination
      break;
    case 'n':
      break;
    default:
      throw std::invalid_argument("The answer must be 'y' (yes) or 'n' (no)");
    }

    SIR sir0{n - i, i, r, n, 0};
    Pandemic COVID{sir0};

    std::vector<SIR> const totdata = COVID.infection(
        beta, gamma, t,
        vax); // vector containing the values of each parameter per day

    Print(totdata); // prints the grid containing the values of each parameter
                    // per day

  } catch (std::invalid_argument const &e) {
    std::cerr << e.what() << '\n';
  } // ?
}
