// 2main.cpp

#include <iostream>
#include <thread>

#include "2world.hpp"

int main()  {
              double T = 0 ;
              double L = 0 ;
              double initial_infected = 0 ;
              double beta = 0 ;
              double gamma = 0 ;
              bool vax = false ;
              bool lockdown = false ;
              char v = 'n' ;
              char l = 'n' ;

              Launch();

              try {
                    std::cout << "VACCINATION:\n"
                                "If more than 30% of the total number of Cells is infected, "
                                "do you want to vaccinate the population? (y/n)\n" ;
                    std::cin >> v ;
                    std::cout << "\n" ;

                    while (v!='y' && v!='n') { 
                        std::cout << "Invalid argument. The answer must be y (yes) or n (no)" ;
                        std::cin >> v ;
                      }

                    if (v=='y') { vax = true ; }

                    std::cout << "QUARANTINE:\n"
                                "If more than 50% of the total number of Cells is infected, "
                                "do you want a quarantine? (y/n)\n" ;
                    std::cin >> l ;
                    std::cout << "\n" ;

                    while (l!='y' && l!='n') { 
                        std::cout << "Invalid argument. The answer must be y (yes) or n (no)" ;
                        std::cin >> l ;
                      }

                    if (l=='y') { lockdown = true ; }

                    std::cout << "Please input N° of days, Length of world, number of "
                                 "infected, probability of infection and probability of recovery"
                              << '\n' ;
                    std::cin >> T >> L >> initial_infected >> beta >> gamma ;

                    CheckInput(T, L, beta, gamma, initial_infected) ;   // checks if user's imputs have valid arguments

                    std::vector<std::vector<Cell>> grid(L, std::vector<Cell>(L, Cell::s)) ;   // creates a LxL grid containing only 's'

                    std::vector<Point> possible_cells = vector_cs(L, grid) ;

                    for (int k = 0; k < initial_infected; k++)  {   // infects cells based on user's input (changes 's' into 'i')
                          int Randomnumber = 0 ;
                          std::random_device rng ;
                          std::default_random_engine prng{rng()} ;
                          std::uniform_int_distribution<int> p(0, L * L - 1 - k) ;
                          Randomnumber = p(prng) ;
                          Point NewInfected = possible_cells[Randomnumber] ;
                          int x = NewInfected.a ;
                          int y = NewInfected.b ;
                          assert(grid[x][y] == Cell::s) ;
                          grid[x][y] = Cell::i ;
                          possible_cells.erase(possible_cells.begin() + Randomnumber) ;
                      }                   

                    World mondo(L, initial_infected, grid) ;

                    bool v_start = false ;
                    double const beta_init = beta ;

                    for (int k = 0; k < T; k++) {  // loop per day
                      if (static_cast<double>(initial_infected) / static_cast<double>(L * L) > 0.3)
                        {v_start = true ;}
                      mondo.draw_grid() ;
                      beta = beta_init ;
                      mondo.day(beta, gamma, vax, lockdown, v_start) ;
                      std::this_thread::sleep_for(std::chrono::milliseconds(400)) ;
                    }
                  }
              catch (std::invalid_argument const& e) { std::cerr <<e.what() <<'\n' ; }
            }
