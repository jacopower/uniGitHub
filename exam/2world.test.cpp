// world.test

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "world.hpp"

TEST_CASE("Testing CheckInput") {
  SUBCASE("T is not valid") {
    double T = -10;
    double L = 20;
    double beta = 0.1;
    double gamma = 0.1;
    double initial_infected = 10;
    CheckInput(T, L, beta, gamma, initial_infected);
    CHECK(T == 10);
  }
  SUBCASE("L is not valid") {
    double T = 10;
    double L = -100;
    double beta = 0.1;
    double gamma = 0.1;
    double initial_infected = 10;
    CheckInput(T, L, beta, gamma, initial_infected);
    CHECK(L == 30);
  }
  SUBCASE("Beta is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double beta = -15;
    double gamma = 0.1;
    double initial_infected = 0;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Beta is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double beta = 15;
    double gamma = 0.1;
    double initial_infected = 0;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Gamma is not valid (less than 0)") {
    double T = 10;
    double L = 20;
    double beta = 0.1;
    double gamma = -1;
    double initial_infected = 0;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Gamma is not valid (greater than 1)") {
    double T = 10;
    double L = 20;
    double beta = 0.1;
    double gamma = 15;
    double initial_infected = 0;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Initial_infected is not valid") {
    double T = 10;
    double L = 20;
    double beta = 0.1;
    double gamma = 0.1;
    double initial_infected = -10;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
  SUBCASE("Initial_infected is out of bounds") {
    double T = 10;
    double L = 10;
    double beta = 0.1;
    double gamma = 0.1;
    double initial_infected = 200;
    CHECK_THROWS_AS(CheckInput(T, L, beta, gamma, initial_infected),
                    const std::invalid_argument&);
  }
}

TEST_CASE("Testing vector_cs") {
  SUBCASE("L is negative") {
    std::vector<std::vector<Cell>> grid(3, std::vector<Cell>(3, Cell::s));
    CHECK_THROWS_AS(vector_cs(-3, grid), const std::invalid_argument&);
  }
  SUBCASE("L is 0") {
    std::vector<std::vector<Cell>> grid(0, std::vector<Cell>(0, Cell::s));
    std::vector<Point> v = vector_cs(0, grid);
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
    std::vector<Point> possible_cells = vector_cs(L, grid);

    for (int k = 0; k < initial_infected; k++) {
      int Randomnumber = 0;
      std::random_device rng;
      std::default_random_engine prng{rng()};
      std::uniform_int_distribution<int> p(0, L * L - 1 - k);
      Randomnumber = p(prng);
      Point NewInfected = possible_cells[Randomnumber];
      int x = NewInfected.a;
      int y = NewInfected.b;
      grid[x][y] = Cell::i;
      possible_cells.erase(possible_cells.begin() + Randomnumber);
    }

    World mondo(L, initial_infected, grid);  // creazione mondo

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
    std::vector<Point> possible_cells = vector_cs(L, grid);
    for (int k = 0; k < initial_infected; k++) {
      int Randomnumber = 0;
      std::random_device rng;
      std::default_random_engine prng{rng()};
      std::uniform_int_distribution<int> p(0, L * L - 1 - k);
      Randomnumber = p(prng);
      Point NewInfected = possible_cells[Randomnumber];
      int x = NewInfected.a;
      int y = NewInfected.b;
      grid[x][y] = Cell::i;
      possible_cells.erase(possible_cells.begin() + Randomnumber);
    }

    World mondo(L, initial_infected, grid);  // creazione mondo

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
    std::vector<Point> possible_cells = vector_cs(L, grid);

    for (int k = 0; k < initial_infected; k++) {
      int Randomnumber = 0;
      std::random_device rng;
      std::default_random_engine prng{rng()};
      std::uniform_int_distribution<int> p(0, L * L - 1 - k);
      Randomnumber = p(prng);
      Point NewInfected = possible_cells[Randomnumber];
      int x = NewInfected.a;
      int y = NewInfected.b;
      grid[x][y] = Cell::i;
      possible_cells.erase(possible_cells.begin() + Randomnumber);
    }

    World mondo(L, initial_infected, grid);  // creazione mondo

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
    std::vector<Point> possible_cells = vector_cs(L, grid);

    for (int k = 0; k < initial_infected; k++) {
      int Randomnumber = 0;
      std::random_device rng;
      std::default_random_engine prng{rng()};
      std::uniform_int_distribution<int> p(0, L * L - 1 - k);
      Randomnumber = p(prng);
      Point NewInfected = possible_cells[Randomnumber];
      int x = NewInfected.a;
      int y = NewInfected.b;
      grid[x][y] = Cell::i;
      possible_cells.erase(possible_cells.begin() + Randomnumber);
    }

    World mondo(L, initial_infected, grid);  // creazione mondo

    for (int k = 0; k < T; k++) {  // loop giorni
      mondo.day(beta, gamma, vax, lockdown, v_start);
    }
    CHECK(mondo.get_I() == 0);
    CHECK(mondo.get_R() == initial_infected);
 }
}
