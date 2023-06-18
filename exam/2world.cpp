// 2world.cpp

#include "2world.hpp"

World::World(int L, int Infected, std::vector<std::vector<Cell>> initial_grid)  : m_L{L} ,
                                                                                  S{(L * L) - Infected} ,
                                                                                  I{Infected} ,
                                                                                  R{0} ,
                                                                                  V{0} ,
                                                                                  Q{0} ,
                                                                                  m_grid{initial_grid}
                                                                                {}

std::vector<std::vector<Cell>> World::get_grid()  { return m_grid ; }

double World::get_L()  { return m_L ; }

int World::get_S()  { return S ; }

int World::get_I()  { return I ; }

int World::get_R()  { return R ; }

int World::get_V()  { return V ; } 

int World::HowManyCloseInfected(int i, int j)
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
    throw std::invalid_argument("Something went wrong: HowManyCloseInfected has found an out of bound cell") ; // where's the try and catch?
  }

void World::vaccine() 
{
    std::vector<Point> PossibleCells = vector_cs(m_L, m_grid) ;
    if(PossibleCells.empty() == false)
      {
        std::uniform_int_distribution<int> p(0, PossibleCells.size() - 1) ;
        int Randomnumber = 0 ;
        std::random_device rng ;
        std::default_random_engine prng{rng()} ;
        Randomnumber = p(prng) ;
        Point NewInfected = PossibleCells[Randomnumber] ;
        int x = NewInfected.a ;
        int y = NewInfected.b ;

        assert(m_grid[x][y] == Cell::s) ;
        m_grid[x][y] = Cell::r ;
        S -= 1 ;
        R += 1 ;
        V += 1 ;
      }
  }

void World::quarantine(double& beta) { beta = beta * 0.5 ; }


void World::day(double& beta, double const& gamma, bool vax, bool lockdown, bool v_start )
  {
    std::vector<std::vector<Cell>> last_grid = get_grid() ;

    double Randomnumber = 0 ;
    std::random_device rng ;
    std::default_random_engine prng{rng()} ;
    std::uniform_real_distribution<double> p(0, 1) ;

    if(lockdown == true && static_cast<double>(I) / static_cast<double>(m_L * m_L) >= 0.5) 
      {
        quarantine(beta) ;
        Q = 1 ;
      }
      else { Q = 0 ;}


    if(vax == true && v_start == true)
      {
        for (int i = 0; i < ceil(static_cast<double>(m_L * m_L) / 100); ++i)
          {
            vaccine() ;
          }
      }

    for(int i = 0; i < m_L; i++)
      {
        assert(i >= 0) ;
        for(int j = 0; j < m_L; j++)
          {
            assert(j >= 0) ;
            if(last_grid[i][j] == Cell::s)
              {
                Randomnumber = p(prng) ;
                if(Randomnumber <= (HowManyCloseInfected(i, j) * beta / 8))
                  {
                    last_grid[i][j] = Cell::i ;
                    I += 1 ;
                    S -= 1 ;
                  }
              }
            else if(last_grid[i][j] == Cell::i) 
              {
                Randomnumber = p(prng) ;
                if (Randomnumber <= gamma)
                  {
                    last_grid[i][j] = Cell::r ;
                    I -= 1 ;
                    R += 1 ;
                  }
              }
          }
      }
    m_grid = last_grid ;

    assert(S + I + R == m_L * m_L) ;
  }

void World::draw_grid()
  {
    std::cout << std::string(50, '\n') ;
    for(int j = 0; j < m_L; j++)
      {
        for(int i = 0; i < m_L; i++)
          {
            if(m_grid[i][j] == Cell::s)
              {
                std::cout << "\e[0;37m"
                          << " s " ;
              }
            if(m_grid[i][j] == Cell::i)
              {
                std::cout << "\e[0;31m"
                          << " i " ;
              }
            if(m_grid[i][j] == Cell::r)
              {
                std::cout << "\e[0;32m"
                          << " r " ;
              }
          }
        std::cout << "\e[0;37m"
                  << "\n" ;
      }
    std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+\n"
                 "|     S     |     I     |     R     |     N     |     V     |     Q     |\n"
                 "+-----------+-----------+-----------+-----------+-----------+-----------+\n"
              << std::fixed ;

    std::cout << "| " << std::setw(5) << S << std::setw(7) << " | "
              << std::setw(5) << I << std::setw(7) << " | " 
              << std::setw(5) << R << std::setw(7) << " | " 
              << std::setw(5) << S + I + R << std::setw(7) << " | " 
              << std::setw(5) << V << std::setw(7) << " | "  
              << std::setw(5) << Q << std::setw(7) << " |\n" ;

    std::cout << "+-----------+-----------+-----------+-----------+-----------+-----------+"
                 "\n" ;
  }

std::vector<Point> vector_cs(int L, std::vector<std::vector<Cell>> grid)
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
                double const& initial_infected)
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

void Launch()
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
