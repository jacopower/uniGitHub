// 2cell.cpp

#include "2world.hpp"

World::World(int L, int Infected, std::vector<std::vector<Cell>> initial_grid)  : m_L{L} ,
                                                                                  S{(L * L) - Infected} ,
                                                                                  I{Infected} ,
                                                                                  R{0} ,
                                                                                  V{0} ,
                                                                                  Q{0} ,
                                                                                  D{0} ,
                                                                                  m_grid{initial_grid}
                                                                                {}    // initializes a word on day 0

std::vector<std::vector<Cell>> World::get_grid()  { return m_grid ; }   // using those methods to access private inforation to prevent changing them unintentionally
double World::get_L()  { return m_L ; }

int World::get_S()  { return S ; }

int World::get_I()  { return I ; }

int World::get_R()  { return R ; }

int World::get_V()  { return V ; } 

int World::HowManyCloseInfected(int i, int j)   // tells how many infetcted cells one have around (use to determine the infectione of a cell)
  {
    if(i >= 0 && j >= 0)
      {
        int CloseInfected = 0 ;
        for(int r : {-1, 0, 1})   // row
          {  
            for(int c : {-1, 0, 1})   // column
              { 
                if(j + c >= 0 && i + r >= 0 && j + c < m_L && i + r < m_L)
                  {
                    if(m_grid[i + r][j + c] == Cell::i) { CloseInfected += 1 ; }
                  }
              }
          }
        return CloseInfected ;
      }
    throw std::invalid_argument("Something went wrong: HowManyCloseInfected has found an out of bound cell") ;    // the try and catch block ar in the main
  }

void World::vaccine()   // vaccines a sucettible cell (turns 's' into 'r')
{
    std::vector<Point> PossibleCells = vector_cs(m_L, m_grid) ;
    if(PossibleCells.empty() == false)
      {
        std::uniform_int_distribution<int> p(0, PossibleCells.size() - 1) ;
        int Randomnumber = 0 ;
        std::random_device rng ;
        std::default_random_engine prng{rng()} ;
        Randomnumber = p(prng) ;    // explained in 2main.cpp
        Point NewVaccinated = PossibleCells[Randomnumber] ;
        int x = NewVaccinated.a ;
        int y = NewVaccinated.b ;

        assert(m_grid[x][y] == Cell::s) ;
        m_grid[x][y] = Cell::r ;
        S -= 1 ;
        R += 1 ;
        V += 1 ;
      }
  }

void World::quarantine(double& beta) { beta = beta * 0.5 ; }


void World::day(double& beta, double const& gamma, bool vax, bool lockdown, bool v_start )    // changes the parameters of a day to create the following one
  {
    std::vector<std::vector<Cell>> last_grid = get_grid() ;


    if(lockdown == true && static_cast<double>(I) / static_cast<double>(m_L * m_L) >= 0.5) 
      {
        quarantine(beta) ;
        Q = 1 ;   // lockdown on (beta is halved)
      }
      else { Q = 0 ;}   // lockdown off


    if(vax == true && v_start == true)
      {
        for (int i = 0; i < ceil(static_cast<double>(m_L * m_L) / 100); ++i)    // vaccines 1% of population
          {
            vaccine() ;
          }
      }


    double Randomnumber = 0 ;
    std::random_device rng ;
    std::default_random_engine prng{rng()} ;
    std::uniform_real_distribution<double> p(0, 1) ;    // explained in 2main.cpp

    for(int i = 0; i < m_L; i++)
      {
        assert(i >= 0) ;
        for(int j = 0; j < m_L; j++)
          {
            assert(j >= 0) ;
            if(last_grid[i][j] == Cell::s)
              {
                Randomnumber = p(prng) ;
                if(Randomnumber <= (HowManyCloseInfected(i, j) * beta / 8))   // randomly choose if a cell is becoming ill (based on the illness of the surrounding ones)
                  {
                    last_grid[i][j] = Cell::i ;
                    I += 1 ;
                    S -= 1 ;
                  }
              }
            else if(last_grid[i][j] == Cell::i) 
              {
                Randomnumber = p(prng) ;
                if (Randomnumber <= gamma)    // randomly choose if an ill cell is going to recover (based on beta)
                  {
                    last_grid[i][j] = Cell::r ;
                    I -= 1 ;
                    R += 1 ;
                  }
              }
          }
      }
    
    ++D ;

    m_grid = last_grid ;    // update grid

    assert(S + I + R == m_L * m_L) ;
  }

void World::draw_grid()   // draws the grid of the word in a specific day
  {
    std::cout << std::string(50, '\n') ;
    for(int j = 0; j < m_L; j++)    // switches rows
      {
        for(int i = 0; i < m_L; i++)    // switches columns
          {
            if(m_grid[i][j] == Cell::s)
              {
                std::cout << "\e[0;37m"   // setting output color (white)
                          << " s " ;
              }
            if(m_grid[i][j] == Cell::i)
              {
                std::cout << "\e[0;31m"   // red
                          << " i " ;
              }
            if(m_grid[i][j] == Cell::r)
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
              << std::setw(5) << S + I + R << std::setw(7) << " | " 
              << std::setw(5) << S << std::setw(7) << " | "
              << std::setw(5) << I << std::setw(7) << " | " 
              << std::setw(5) << R << std::setw(7) << " | " 
              << std::setw(5) << V << std::setw(7) << " | "  
              << std::setw(5) << Q << std::setw(7) << " |\n" ;

    std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+-----------+"
                 "\n" ;
  }

std::vector<Point> vector_cs(int L, std::vector<std::vector<Cell>> grid)    // contains the posotions of 's' cells
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
    throw ::std::invalid_argument("L must be a positive integer");
  }

void CheckInput(double& T,
                double& L,
                double const& beta,
                double const& gamma,
                double const& initial_infected)   // checks if user's imputs have valid arguments
  {
    if(!std::cin.good())
      {
        throw std::invalid_argument("The given input contains one or more errors") ;
      }

    if(floor(T) != ceil(T)) 
      {
        throw std::invalid_argument("Time (T) must be a positive integer") ;
      }

    if(floor(L) != ceil(L))
      {
        throw std::invalid_argument("Length (L) must be a positive integer") ;
      }

    if(beta < 0 || beta > 1)
      {  
        throw std::invalid_argument("Beta must be a double greater than 0 and smaller than 1") ;
      }

    if(gamma < 0 || gamma > 1)
      {  
        throw std::invalid_argument("Gamma must be a double greater than 0 and smaller than 1") ;
      }

    if(T < 0)
      { 
        T = -T ;
        std::cerr << "Time (T) has been converted to positive" << '\n' ;
      }

    if(L < 5 || L > 40)
      { 
        L = 30 ;
        std::cerr << "Lenght (L) has been converted to 30" << '\n' ;
      }

    if(initial_infected < 0 || initial_infected > L * L)
      {
        throw std::invalid_argument("The number of initial infected people must be positive and smaller than L*L") ;
      }
  }

void Launch()   // intro
  { 
    std::cout << std::string(50, '\n') ;
    std::cout << "+--------------------------------------------------------------"
                "---------+\n"
                "|"
              << std::string(26, ' ') << "PANDEMIC SIMULATION"
              << std::string(26, ' ') << "|"
              << "\n"
                "+--------------------------------------------------------------"
                "---------+\n\n" ;
    std::cout << "If you wish to abort, at any time, please press Ctrl+C on your "
                "Keyboard\n\n"
                "+--------------------------------------------------------------"
                "---------+\n\n"
                "If you wish to continue with the simulation, please answer the "
                "following questions:\n\n" ;
  }
