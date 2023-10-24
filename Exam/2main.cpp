// 2main.cpp

#include "2cell.hpp"

using grid_t = std::vector<std::vector<Cell>>;

int main() {
  double t = 0;
  double l = 0;
  double i = 0;
  double beta = 0;
  double gamma = 0;
  bool vax = false;
  bool lockdown = false;
  char v = 'n';
  char q = 'n';

  Intro();

  try {
    std::cout
        << "Please input N° of days, Length of world, number of infected, "
           "probability of infection and probability of recovery\n";
    std::cin >> t >> l >> i >> beta >> gamma;
    std::cout << '\n';

    CheckInput(t, l, i, beta,
               gamma); // checks if user's imputs have valid arguments

    std::cout << "VACCINATION:\n"
                 "If more than 30% of the total number of Cells is infected, "
                 "do you want to vaccinate the population? (y/n)\n";
    std::cin >> v;
    std::cout << '\n';

    while (v != 'y' && v != 'n') {
      std::cout << "Invalid argument. The answer must be y (yes) or n (no)";
      std::cin >> v;
    }

    if (v == 'y') {
      vax = true;
    }

    std::cout << "QUARANTINE:\n"
                 "If more than 50% of the total number of Cells is infected, "
                 "do you want a quarantine? (y/n)\n";
    std::cin >> q;
    std::cout << '\n';

    while (q != 'y' && q != 'n') {
      std::cout << "Invalid argument. The answer must be y (yes) or n (no)";
      std::cin >> q;
    }

    if (q == 'y') {
      lockdown = true;
    }

    grid_t grid(l, std::vector<Cell>(
                       l, Cell::s)); // creates a LxL grid containing only 's'

    std::vector<Point> possible_cells =
        position_s(l, grid); // contains the positions of 's' cells

    World mondo(l, i, grid);
    mondo.setWorld(possible_cells);

    double const beta_init = beta;
    bool v_start = false;

    for (int k = 0; k < t; k++) { // loop per day
      mondo.draw_grid();

      beta = beta_init;
      if (static_cast<double>(mondo.get_I()) /
              static_cast<double>(mondo.get_L() * mondo.get_L()) >
          0.3) {
        v_start = true;
      }

      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
  } catch (std::invalid_argument const &e) {
    std::cerr << e.what() << '\n';
  }
}
