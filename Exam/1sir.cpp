// 1sir.cpp

#include "1sir.hpp"

Pandemic::Pandemic(SIR const &initial_SIR) : SIR_0{initial_SIR} {}

std::vector<SIR>
Pandemic::infection(double beta, double gamma, double T,
                    bool vax) // the parameters are given from user
{
  std::vector<SIR> result{SIR_0};

  auto const &N = SIR_0.N;
  bool vstart = false;

  assert(!result.empty()); // checks if 'result' is not empty (abort if empty)

  for (int j = 1; j < T; ++j) { // looping once a day
    SIR new_SIR = result.back();
    double S_last = new_SIR.S;
    double I_last = new_SIR.I;
    double R_last = new_SIR.R;

    if (I_last == N) { // if they are all infected they all recover
      new_SIR.I = 0;
      new_SIR.R = N;
    } else if (I_last == 1) { // if there is 1 infected, he recovers
      new_SIR.I = 0;
      new_SIR.R = R_last + 1;
    }

    else {
      new_SIR.S = S_last - round(beta * S_last * I_last / (N - 1));
      new_SIR.I = I_last + round(beta * S_last * I_last / (N - 1)) -
                  round(gamma * I_last);

      new_SIR.R = N - (new_SIR.S + new_SIR.I);

      assert(new_SIR.R == R_last + round(gamma * I_last));
      assert(new_SIR.S >= 0 && new_SIR.I >= 0 && new_SIR.R >= 0);

      vstart = false;
      if (I_last / N > 0.3) {
        vstart = true;
      } // if infected are above 30% of pop, vaccinate

      if (vax == true && vstart == true &&
          new_SIR.S > ceil(N / 100)) { // vaccination of 1% of pop
        new_SIR.S -= ceil(N / 100);
        new_SIR.R += ceil(N / 100);
        new_SIR.V += ceil(N / 100);
      } else if (vax == true && vstart == true && new_SIR.S <= ceil(N / 100) &&
                 new_SIR.S > 0) // vaccination of 1 person
      {
        new_SIR.S -= 1;
        new_SIR.R += 1;
        new_SIR.V += 1;
      }
    }

    assert(new_SIR.S + new_SIR.I + new_SIR.R == N);
    assert(floor(new_SIR.S) == ceil(new_SIR.S) &&
           floor(new_SIR.I) == ceil(new_SIR.I) &&
           floor(new_SIR.R) == ceil(new_SIR.R));

    result.push_back(new_SIR); // at the end of the loop, 'result' contains T
                               // SIR type object, in chronological order
  }

  return result;
}

void CheckInput(
    double const &T, // checks if user's imputs have valid arguments
    double const &N, double const &I, double const &beta,
    double const &gamma) // checks if user's imputs have valid arguments
{
  if (!std::cin.good()) {
    throw std::invalid_argument(
        "The given input contains one or more errors"); // there will be a try
                                                        // block and a catch
                                                        // block in the main
  }
  if (floor(T) != ceil(T) || T < 0) {
    throw std::invalid_argument("N° of days (T) must be a positive integer");
  }
  if (floor(N) != ceil(N) || N < 0) {
    throw std::invalid_argument("N° of people (N) must be a positive integer");
  }
  if (floor(I) != ceil(I) || I < 0) {
    throw std::invalid_argument(
        "N° of infecteds (I) must be a positive integer");
  }
  if (I > N) {
    throw std::invalid_argument(
        "N° of infecteds (I) must be smaller than N° of people (N)");
  }
  if (beta < 0 || beta > 1) {
    throw std::invalid_argument(
        "Beta must be a double greater than 0 and smaller than 1");
  }
  if (gamma < 0 || gamma > 1) {
    throw std::invalid_argument(
        "Gamma must be a double greater than 0 and smaller than 1");
  }
}

void Print(std::vector<SIR> const &SIRp) {
  int day = 0;

  std::cout << "+-----------+-----------+-----------+-----------+-----------+--"
               "---------+\n"
               "|     D     |     S     |     I     |     R     |     N     |  "
               "   V     |\n"
               "+-----------+-----------+-----------+-----------+-----------+--"
               "---------+\n"
            << std::fixed;
  for (auto &sir : SIRp) {
    ++day; // updates the day
    std::cout << "| " << std::setw(9) << day
              << " | " // setw(n) sets the with of the following output/input to
                       // n char (fills fith spaces the remaning chars)
              << std::setw(9) << static_cast<int>(sir.S)
              << " | " // 9 char (sir.s + spaces = 9) + ' | '
              << std::setw(9) << static_cast<int>(sir.I) << " | "
              << std::setw(9) << static_cast<int>(sir.R) << " | "
              << std::setw(9) << static_cast<int>(sir.S + sir.I + sir.R)
              << " | " << std::setw(9) << sir.V << " |\n";
  }
  std::cout << "+-----------+-----------+-----------+-----------+-----------+--"
               "---------+"
            << "\n\n";
}

void Intro() {
  std::cout << "\n\n\n"
            << "+" << std::string(108, '-') << "+\n"
            << std::string(17, ' ') << "|" << std::string(27, ' ')
            << "PANDEMIC SIMULATION" << std::string(27, ' ') << "|\n"
            << "+" << std::string(108, '-') << "+\n"
            << std::string(17, ' ')
            << "|  This simulation uses the SIR model to study the course of "
               "an epidemic  |\n"
            << "+" << std::string(108, '-') << "+\n"
            << std::string(17, ' ')
            << "| If you wish to abort, at any time, please press Ctrl+C on "
               "your Keyboard |\n"
            << "+" << std::string(108, '-') << "+\n\n";
}
