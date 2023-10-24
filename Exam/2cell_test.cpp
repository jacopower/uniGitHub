// 2cell.test

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "2cell.hpp"

using grid_t = std::vector<std::vector<Cell>>;

TEST_CASE("Testing CheckInput()") {
  SUBCASE("T is negative") {
    double T = -10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    std::invalid_argument &);
  }
  SUBCASE("L is not valid") {
    double T = 10;
    double L = -20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    std::invalid_argument &);
  }
  SUBCASE("L is too small/big") {
    double T = 10;
    double L = 2;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    std::invalid_argument &);
    CHECK(L == 20);
  }
  SUBCASE("initial_infected is not valid") {
    double T = 10;
    double L = 20;
    double initial_infected = -250;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
  SUBCASE("initial_infected is out of bounds") {
    double T = 10;
    double L = 20;
    double initial_infected = 500;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
  SUBCASE("beta is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = -0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
  SUBCASE("beta is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 1.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
  SUBCASE("gamma is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = -0.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
  SUBCASE("gamma is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double initial_infected = 250;
    double beta = 0.1;
    double gamma = 1.1;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument &);
  }
}

TEST_CASE("Testing position_s()") {
  SUBCASE("L is negative") {
    grid_t grid(3, std::vector<Cell>(3, Cell::s));
    CHECK_THROWS_AS(position_s(-3, grid), const std::invalid_argument &);
  }
  SUBCASE("L is 0") {
    grid_t grid(0, std::vector<Cell>(0, Cell::s));
    std::vector<Point> v = position_s(0, grid);
    CHECK(v.size() == 0);
  }
}

TEST_CASE("Testing HowManyCloseInfected()") {
  SUBCASE("0 infected nearby") {
    grid_t grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 0, grid);
    CHECK(mondo.HowManyCloseInfected(1, 1) == 0);
  }
  SUBCASE("8 infected nearby") {
    grid_t grid(3, std::vector<Cell>(3, Cell::s));
    grid[0][0] = Cell::i;
    grid[0][1] = Cell::i;
    grid[0][2] = Cell::i;
    grid[1][0] = Cell::i;
    grid[1][2] = Cell::i;
    grid[2][0] = Cell::i;
    grid[2][1] = Cell::i;
    grid[2][2] = Cell::i;
    World mondo(3, 8, grid);
    CHECK(mondo.HowManyCloseInfected(1, 1) == 8);
  }
  SUBCASE("Invalid x") {
    grid_t grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 1, grid);
    CHECK_THROWS_AS(mondo.HowManyCloseInfected(-1, 2),
                    const std::invalid_argument &);
  }
  SUBCASE("Invalid y") {
    grid_t grid(3, std::vector<Cell>(3, Cell::s));
    World mondo(3, 1, grid);
    CHECK_THROWS_AS(mondo.HowManyCloseInfected(1, -2),
                    const std::invalid_argument &);
  }
}

TEST_CASE("Testing day() in limit cases") {
  SUBCASE("Testing beta=0 and gamma=0") {
    double T = 100;
    double L = 20;
    double initial_infected = 0;
    double beta_init = 0;
    double gamma = 0;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false;

    grid_t grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);
    mondo.setWorld(possible_cells);

    for (int k = 0; k < T; k++) {

      double beta = beta_init;
      if (static_cast<double>(mondo.get_I()) /
              static_cast<double>(mondo.get_L() * mondo.get_L()) >
          0.3) {
        v_start = true;
      }

      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_S() == L * L);
    CHECK(mondo.get_R() == 0);
    CHECK(mondo.get_I() == 0);
  }
  SUBCASE("Testing beta=1 and gamma=1") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta_init = 1;
    double gamma = 1;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false;

    grid_t grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);
    mondo.setWorld(possible_cells);

    for (int k = 0; k < T; k++) {

      double beta = beta_init;
      if (static_cast<double>(mondo.get_I()) /
              static_cast<double>(mondo.get_L() * mondo.get_L()) >
          0.3) {
        v_start = true;
      }

      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == 0);
    // non si controllano rimossi e suscettibili a causa della casualità
    // dell'infezione tuttavia sicuramente il numero degli infetti è 0
  }
  SUBCASE("Testing beta=1 and gamma=0") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta_init = 1;
    double gamma = 0;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false;

    grid_t grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);
    mondo.setWorld(possible_cells);

    for (int k = 0; k < T; k++) {

      double beta = beta_init;
      if (static_cast<double>(mondo.get_I()) /
              static_cast<double>(mondo.get_L() * mondo.get_L()) >
          0.3) {
        v_start = true;
      }

      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == L * L);
    CHECK(mondo.get_R() == 0);
    CHECK(mondo.get_S() == 0);
  }
  SUBCASE("Testing beta=0 and gamma=1") {
    double T = 100;
    double L = 20;
    double initial_infected = 100;
    double beta_init = 0;
    double gamma = 1;
    bool vax = false;
    bool lockdown = false;
    bool v_start = false;

    grid_t grid(L, std::vector<Cell>(L, Cell::s));
    std::vector<Point> possible_cells = position_s(L, grid);

    World mondo(L, initial_infected, grid);

    double beta = beta_init;
    if (static_cast<double>(mondo.get_I()) /
            static_cast<double>(mondo.get_L() * mondo.get_L()) >
        0.3) {
      v_start = true;
    }

    mondo.setWorld(possible_cells);

    for (int k = 0; k < T; k++) {
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == 0);
    CHECK(mondo.get_R() == initial_infected);
  }
}