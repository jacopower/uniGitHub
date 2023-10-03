// 2cell.test

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "2cell.hpp"

TEST_CASE("Testing CheckInput") {
  SUBCASE("T is negative") {
    double T = -10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 0.1;
    CheckInput(T, L, beta, gamma, initial_infected);
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected), std::invalid_argument&);
  }
  SUBCASE("L is not valid") {
    double T = 10;
    double L = -20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 0.1;
    CheckInput(T, L, beta, gamma, initial_infected);
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected), std::invalid_argument&);
  }
  SUBCASE("Initial_infected is not valid") {
    double T = 10;
    double L = 20;
    double initial_infected = -250;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Initial_infected is out of bounds") {
    double T = 10;
    double L = 20;
    double initial_infected = 500;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Beta is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = -0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Beta is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 1.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Gamma is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = -0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Gamma is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 1.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
}

TEST_CASE("Testing position_s") {
  SUBCASE("L is negative") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    CHECK_THROWS_AS(position_s(-3, grid), const std::invalid_argument&);
  }
  SUBCASE("L is 0") {
    std::vector<std::vector<Cell>> grid(0, std::vector<Cell>(0, Cell::s));
    std::vector<Point> v = position_s(0, grid);
    CHECK(v.size() == 0);
  }
}

TEST_CASE("Testing HowManyCloseInfected") {
  SUBCASE("0 infected nearby") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 0, grid);  // creazione mondo
    CHECK(mondo.HowManyCloseInfected(1, 1) == 0);
  }
  SUBCASE("8 infected nearby") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    grid[0][0] = Cell::i;
    grid[0][1] = Cell::i;
    grid[0][2] = Cell::i;
    grid[1][0] = Cell::i;
    grid[1][2] = Cell::i;
    grid[2][0] = Cell::i;
    grid[2][1] = Cell::i;
    grid[2][2] = Cell::i;
    World mondo(3, 8, grid);  // creazione mondo
    CHECK(mondo.HowManyCloseInfected(1, 1) == 8);
  }
  SUBCASE("Invalid x") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 1, grid);  // creazione mondo
    CHECK_THROWS_AS(mondo.HowManyCloseInfected(-1, 2),
                    const std::invalid_argument&);
  }
  SUBCASE("Invalid y") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 1, grid);  // creazione mondo
    CHECK_THROWS_AS(mondo.HowManyCloseInfected(1, -2),
                    const std::invalid_argument&);
  }
}

TEST_CASE("Testing limit cases") {
  SUBCASE("Testing Beta=0 and Gamma=0") {
    double T = 100;
    double L = 20;
    double initial_infected = 0;
    double beta = 0;
    double gamma = 0;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false ;

    std::vector<std::vector<Cell>> grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);  // creazione mondo
    mondo.setWorld(possible_cells) ;

    for (int k = 0; k < T; k++) {  // loop giorni
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_S() == L * L);
    CHECK(mondo.get_R() == 0);
    CHECK(mondo.get_I() == 0);
  }
  SUBCASE("Testing Beta=1 and Gamma=1") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta = 1;
    double gamma = 1;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false ;

    std::vector<std::vector<Cell>> grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);  // creazione mondo
    mondo.setWorld(possible_cells) ;

    for (int k = 0; k < T; k++) {  // loop giorni
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == 0);
    // non si controllano rimossi e suscettibili a causa della casualità
    // dell'infezione tuttavia sicuramente il numero degli infetti è 0
  }
  SUBCASE("Testing Beta=1 and Gamma=0") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta = 1;
    double gamma = 0;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false ;

    std::vector<std::vector<Cell>> grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);  // creazione mondo
    mondo.setWorld(possible_cells) ;

    for (int k = 0; k < T; k++) {  // loop giorni
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == L * L);
    CHECK(mondo.get_R() == 0);
    CHECK(mondo.get_S() == 0);
  }
  SUBCASE("Testing Beta=0 and Gamma=1") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta = 0;
    double gamma = 1;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false ;

    std::vector<std::vector<Cell>> grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);  // creazione mondo
    mondo.setWorld(possible_cells) ;

    for (int k = 0; k < T; k++) {  // loop giorni
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == 0);
    CHECK(mondo.get_R() == initial_infected);
 }
}
