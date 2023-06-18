#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "pandemic.hpp"

TEST_CASE("testing pandemic")
{
  SUBCASE("testing beta = 0 and gamma = 0")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.I == 5);
    CHECK(sir1.V == 0);
    CHECK(sir1.R == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing beta = 1 and gamma = 1")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 3);
    CHECK(sir1.I == 3);
    CHECK(sir1.R == 4);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing beta = 0.5 and gamma = 0.5")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 4);
    CHECK(sir1.I == 4);
    CHECK(sir1.R == 2);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing beta = 0 and gamma = 1")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 5);
    CHECK(sir1.I == 0);
    CHECK(sir1.R == 5);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing beta = 1 and gamma = 0")
  {
    int T = 5;
    double const N = 10;
    double I = 5;
    double S = N - I;
    double R = 0;
    int V = 0;
    double beta = 1;
    double gamma = 0;
    bool vax = false;
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 0);
    CHECK(sir1.I == 10);
    CHECK(sir1.R == 0);
    CHECK(sir1.V == 0);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing vaccination")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 4);
    CHECK(sir1.I == 5);
    CHECK(sir1.R == 1);
    CHECK(sir1.V == 1);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing vaccination 2")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 0);
    CHECK(sir1.I == 97);
    CHECK(sir1.R == 3);
    CHECK(sir1.V == 3);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
  SUBCASE("testing vaccination 2")
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
    SIR sir0{S, I, R, V};
    Pandemic pandemic{sir0};
    std::vector<SIR> result = pandemic.infection(beta, gamma, T, vax);
    SIR sir1 = result.back();
    CHECK(sir1.S == 490);
    CHECK(sir1.I == 500);
    CHECK(sir1.R == 10);
    CHECK(sir1.V == 10);
    CHECK(sir1.S + sir1.I + sir1.R == N);
  }
}

TEST_CASE("Testing CheckInput")
{
  SUBCASE("t is negative")
  {
    double t = -10;
    int T = 0;
    double N = 1;
    double I = 1;
    double beta = 0.1;
    double gamma = 0.1;
    CheckInput(t, T, N, I, beta, gamma);
    CHECK(t == 10);
    CHECK(T == 10);
  }
  SUBCASE("t is not an integer")
  {
    double t = 10.5;
    int T = 0;
    double N = 1;
    double I = 1;
    double beta = 0.1;
    double gamma = 0.1;
    CheckInput(t, T, N, I, beta, gamma);
    CHECK(T == 10);
  }
  SUBCASE("N is negative")
  {
    double t = 10;
    int T = 0;
    double N = -1;
    double I = 1;
    double beta = 0.1;
    double gamma = 0.1;
    CheckInput(t, T, N, I, beta, gamma);
    CHECK(N == 1);
  }
  SUBCASE("N is not an integer")
  {
    double t = 10;
    int T = 0;
    double N = 1.5;
    double I = 1;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is not an integer")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 0.5;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is negative")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = -1;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("I is bigger than N")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 2;
    double beta = 0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("beta is negative")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 2;
    double beta = -0.1;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("beta is bigger than 1")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 2;
    double beta = 2;
    double gamma = 0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("gamma is negative")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 2;
    double beta = 0.1;
    double gamma = -0.1;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
  SUBCASE("gamma is bigger than 1")
  {
    double t = 10;
    int T = 0;
    double N = 1;
    double I = 2;
    double beta = 0.1;
    double gamma = 2;
    CHECK_THROWS_AS(CheckInput(t, T, N, I, beta, gamma), std::invalid_argument);
  }
}