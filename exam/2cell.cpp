// 2cell.cpp

#include "2cell.hpp"

World::World(int L, int I, grid_t initial_grid)  : L_0{L} ,
                                                                                  S{(L * L) - I} ,
                                                                                  I_0{I} ,
                                                                                  R{0} ,
                                                                                  V{0} ,
                                                                                  Q{0} ,
                                                                                  D{0} ,
                                                                                  grid_0{initial_grid}
                                                                                {}    // initializes a word on day 0

grid_t World::get_grid()  { return grid_0 ; }   // using those methods to access private inforation to prevent changing them unintentionally

int World::get_L()  { return L_0 ; }

int World::get_S()  { return S ; }

int World::get_I()  { return I_0 ; }

int World::get_R()  { return R ; }

int World::get_V()  { return V ; } 

void World::setWorld(std::vector<Point> possible_cells)
{
  Point NewInfected ;

  for (int k = 0; k < I_0; k++)    // infects cells based on user's input (changes 's' into 'i')
  {
      std::uniform_int_distribution<int> p(0, L_0 * L_0 - 1 - k) ;    // uniform distrubution between 0 and L*L-1-k
      std::random_device rng ;    // gives random num 
      std::default_random_engine prng{rng()} ;    // gives random num based on the seed rng()
      int Randomnumber = 0 ;
      Randomnumber = p(prng) ;    // randomly choose a num from the distribution p using the generating seed prng

      NewInfected = possible_cells[Randomnumber] ;    // randomly choose a cell to be infected
      int x = NewInfected.a ;
      int y = NewInfected.b ;
      assert(grid_0[x][y] == Cell::s) ;
      grid_0[x][y] = Cell::i ;
      possible_cells.erase(possible_cells.begin() + Randomnumber) ;
  }
}

int World::HowManyCloseInfected(int i, int j)   // tells how many infected cells one have around (use to determine the infection of a cell)
{
  if(i >= 0 && j >= 0)    // checks for valid coordinates
    {
      int CloseInfected = 0 ;
      for(int r : {-1, 0, 1})   // row
        {  
          for(int c : {-1, 0, 1})   // column
            { 
              if(j + c >= 0 && i + r >= 0 && j + c < L_0 && i + r < L_0)    // checks for valid coordinates
                {
                  if(grid_0[i + r][j + c] == Cell::i) { CloseInfected += 1 ; }
                }
            }
        }
      return CloseInfected ;
    }
  else throw std::invalid_argument("Something went wrong: HowManyCloseInfected has found an out of bound cell") ;    // the try and catch block ar in the main
}

void World::vaccine()   // vaccines one sucettible cell (turns 's' into 'r')
{
  std::vector<Point> PossibleCells = position_s(L_0, grid_0) ;
  if(PossibleCells.empty() == false)
    {
      std::uniform_int_distribution<int> p(0, PossibleCells.size() - 1) ;
      std::random_device rng ;
      std::default_random_engine prng{rng()} ;
      int Randomnumber = 0 ;
      Randomnumber = p(prng) ;    // explained in 2main.cpp

      Point NewVaccinated = PossibleCells[Randomnumber] ;   // randomly choose a cell to be vaccinated
      int x = NewVaccinated.a ;
      int y = NewVaccinated.b ;

      assert(grid_0[x][y] == Cell::s) ;
      grid_0[x][y] = Cell::r ;
      S -= 1 ;
      R += 1 ;
      V += 1 ;
    }
}

void World::quarantine(double& beta) { beta = beta * 0.5 ; }    // halves the probability of infection

void World::day(double& beta, double const& gamma, bool vax, bool lockdown, bool v_start )    // changes the parameters of a day to create the following one
{
  grid_t last_grid = get_grid() ;

  if (Q==0) {
    if(lockdown == true && static_cast<double>(I_0) / static_cast<double>(L_0 * L_0) >= 0.5) 
      {
        Q = 1 ;   // lockdown on (beta is halved)
        quarantine(beta) ;
      }
    else { Q = 0 ;}   // lockdown off
  }
  else if (Q==1){
    if(static_cast<double>(I_0) / static_cast<double>(L_0 * L_0) <= 0.3) 
      { Q = 0 ; }   // lockdown on (beta is halved)
    else { quarantine(beta) ;}   // lockdown off
  }

  if(vax == true && v_start == true)
    {
      for (int i = 0; i < ceil(static_cast<double>(L_0 * L_0) / 100); ++i)    // vaccines 1% of population
        {
          vaccine() ;
        }
    }


  for(int i = 0; i < L_0; i++)    // loops rows
  {
    double Randomnumber = 0 ;
    
    for(int j = 0; j < L_0; j++)    // loops columns
    {
      if(last_grid[i][j] == Cell::s)
      {
        std::random_device rng ;
        std::default_random_engine prng{rng()} ;
        std::uniform_real_distribution<double> p(0, 1) ;    // explained in setWorld()
        Randomnumber = p(prng) ;
        if(Randomnumber <= (beta * HowManyCloseInfected(i, j)/8))   // randomly choose if a cell is becoming ill (based on probability and the illness of the surrounding ones)
        {
          last_grid[i][j] = Cell::i ;
          I_0 += 1 ;
          S -= 1 ;
        }
      }
      else if(last_grid[i][j] == Cell::i) 
      {
        std::random_device rng ;
        std::default_random_engine prng{rng()} ;
        std::uniform_real_distribution<double> p(0, 1) ;    // explained in setWorld()
        Randomnumber = p(prng) ;
        if (Randomnumber <= gamma)    // randomly choose if an ill cell is going to recover (based on beta)
        {
          last_grid[i][j] = Cell::r ;
          I_0 -= 1 ;
          R += 1 ;
        }
      }
    }
  }
  
  ++D ;

  grid_0 = last_grid ;    // update grid

  assert(S + I_0 + R == L_0 * L_0) ;
}

void World::draw_grid()   // draws the grid of the word in a specific day
{
  std::cout << std::string(50, '\n') ;
  for(int j = 0; j < L_0; j++)    // switches rows
    {
      for(int i = 0; i < L_0; i++)    // switches columns
        {
          if(grid_0[i][j] == Cell::s)
            {
              std::cout << "\e[0;37m"   // setting output color (white)
                        << " s " ;
            }
          if(grid_0[i][j] == Cell::i)
            {
              std::cout << "\e[0;31m"   // red
                        << " i " ;
            }
          if(grid_0[i][j] == Cell::r)
            {
              std::cout << "\e[0;32m"   // green
                        << " r " ;
            }
        }
      std::cout << "\e[0;37m"
                << "\n" ;
    }
  std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n"
                "|     D     |     N     |     S     |     I     |     R     |     V     |     Q     |\n"
                "+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n"
            << std::fixed ;

  std::cout << "| " 
            << std::setw(5) << D << std::setw(7) << " | "
            << std::setw(5) << S + I_0 + R << std::setw(7) << " | " 
            << std::setw(5) << S << std::setw(7) << " | "
            << std::setw(5) << I_0 << std::setw(7) << " | " 
            << std::setw(5) << R << std::setw(7) << " | " 
            << std::setw(5) << V << std::setw(7) << " | "  
            << std::setw(5) << Q << std::setw(7) << " |\n" ;

  std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+-----------+"
                "\n\n" ;
}

std::vector<Point> position_s(int L, grid_t grid)    // contains the posotions of 's' cells
{
  if(L >= 0)
    {
      std::vector<Point> PossibleCells(0, {0, 0}) ;
          for(int i = 0; i < L; i++)
            {
              for(int j = 0; j < L; j++)
                {
                  Point p{i, j} ;
                  if(grid[i][j] == Cell::s)
                    {
                      PossibleCells.push_back(p) ;
                    }
                }
            }
      return PossibleCells;
    }
  else throw std::invalid_argument("L must be a positive integer");
}

void CheckInput(double& T,
                double& L,
                double const& I,
                double const& beta,
                double const& gamma)   // checks if user's imputs have valid arguments
{
  if (!std::cin.good()) {
    throw std::invalid_argument("The given input contains one or more errors\n\n") ;    // there will be a try block and a catch block in the main
  }
  if (floor(T) != ceil(T) || T < 0) {
    throw std::invalid_argument("N° of days (T) must be a positive integer\n\n") ;
  }
  if (floor(L) != ceil(L) || L < 0) {
    throw std::invalid_argument("N° of people (N) must be a positive integer\n\n") ;
  }
  if(L < 5 || L > 40) { 
    L = 20 ;
    std::cerr << "Lenght (L) has been converted to 20\n\n" ;
  }
  if (floor(I) != ceil(I)) {
    throw std::invalid_argument("N° of infected people (I) must be an integer\n\n") ;
  }
  if(I < 0 || I > L * L){
    throw std::invalid_argument("The number of initial infected people must be positive and smaller than L*L\n\n") ;
  }
  if (beta < 0 || beta > 1) {
    throw std::invalid_argument("Beta must be a double greater than 0 and smaller than 1\n\n") ;
  }
  if (gamma < 0 || gamma > 1) {
    throw std::invalid_argument("Gamma must be a double greater than 0 and smaller than 1\n\n") ;
  }

  }

void Intro()   // prints an intro
{ 
  std::cout << "\n\n\n"
            << "+"<< std::string(112, '-') << "+\n"
            << std::string(19, ' ') << "|"
            << std::string(27, ' ') << "PANDEMIC SIMULATION"
            << std::string(27, ' ') << "|\n"
            << "+"<< std::string(112, '-') << "+\n"
            << std::string(19, ' ') << "|  This simulation uses the SIR model to study the course of an epidemic  |\n"
            << "+"<< std::string(112, '-') << "+\n"
            << std::string(19, ' ') << "| If you wish to abort, at any time, please press Ctrl+C on your Keyboard |\n"
            << "+"<< std::string(112, '-') << "+\n\n" ;
}
