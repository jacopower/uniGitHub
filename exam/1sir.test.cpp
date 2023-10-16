// sir.test

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "1sir.hpp"

TEST_CASE("Testing CheckInput()")
{
  SUBCASE("T is negative")
  {
    double T = -100;
    double N = 100;
    double I = 30;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("T is not an integer")
  {
    double T = 99.5;
    double N = 100;
    double I = 30;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("N is negative")
  {
    double T = 100;
    double N = -100;
    double I = 30;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("N is not an integer")
  {
    double T = 100;
    double N = 99.5;
    double I = 30;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is not an integer")
  {
    double T = -100;
    double N = 100;
    double I = 30.5;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is negative")
  {
    double T = -100;
    double N = 100;
    double I = -30;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is bigger than N")
  {
    double T = -100;
    double N = 100;
    double I = 130;
    double beta = 0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("beta is negative")
  {
    double T = -100;
    double N = 100;
    double I = 30;
    double beta = -0.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("beta is bigger than 1")
  {
    double T = -100;
    double N = 100;
    double I = 30;
    double beta = 1.7;
    double gamma = 0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("gamma is negative")
  {
    double T = -100;
    double N = 100;
    double I = 30;
    double beta = 0.7;
    double gamma = -0.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("gamma is bigger than 1")
  {
    double T = -100;
    double N = 100;
    double I = 30;
    double beta = 0.7;
    double gamma = 1.4;
    CHECK_THROWS_AS(CheckInput(T, N, I, beta, gamma), std::invalid_argument);
  }
}

TEST_CASE("Testing pandemic()")
{
  SUBCASE("Testing beta = 0 and gamma = 0")
  {
    int T = 10;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 0;
    double gamma = 0;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.I == 5);
    CHECK(sir1.V == 0);
    CHECK(sir1.R == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing beta = 1 and gamma = 1")
  {
    int T = 2;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 1;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 2);
    CHECK(sir1.I == 3);
    CHECK(sir1.R == 5);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing beta = 0.5 and gamma = 0.5")
  {
    int T = 2;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 0.5;
    double gamma = 0.5;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 4);
    CHECK(sir1.I == 3);
    CHECK(sir1.R == 3);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing beta = 0 and gamma = 1")
  {
    int T = 5;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 0;
    double gamma = 1;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 5);
    CHECK(sir1.I == 0);
    CHECK(sir1.R == 5);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing beta = 1 and gamma = 0")
  {
    int T = 2;
    double const N = 10;
    double I = 4;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 0;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 3);
    CHECK(sir1.I == 7);
    CHECK(sir1.R == 0);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("I = N")
  {
    int T = 2;
    double const N = 100;
    double I = 100;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 0;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 0);
    CHECK(sir1.I == 0);
    CHECK(sir1.R == 100);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
    SUBCASE("I = 1")
  {
    int T = 5;
    double const N = 100;
    double I = 1;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 0;
    bool vax = false;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 99);
    CHECK(sir1.I == 0);
    CHECK(sir1.R == 1);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
}
  SUBCASE("Yesting vaccination")
  {
    int T = 2;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 0;
    double gamma = 0;
    bool vax = true;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 4);
    CHECK(sir1.I == 5);
    CHECK(sir1.R == 1);
    CHECK(sir1.V == 1);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing vaccination 2")
  {
    int T = 10;
    double const N = 100;
    double I = 31;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 0;
    bool vax = true;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 0);
    CHECK(sir1.I == 97);
    CHECK(sir1.R == 3);
    CHECK(sir1.V == 3);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("Testing vaccination 2")
  {
    int T = 2;
    double const N = 1000;
    double I = 500;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 0;
    double gamma = 0;
    bool vax = true;
    SIR sir0{S, I, R, N, V};
    Pandemic COVID{sir0};
    std::vector<SIR> result = COVID.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 490);
    CHECK(sir1.I == 500);
    CHECK(sir1.R == 10);
    CHECK(sir1.V == 10);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
}
