// 2world.hpp

#ifndef WORLD_HPP
#define WORLD_HPP

#include <cassert>
#include <iomanip>
#include <iostream>
#include <random>
#include <typeinfo>
#include <vector>

struct Point { int a, b ; } ;

enum class Cell : char { s, i, r } ;

class World {
    private:
      int m_L ;         // grid side length 
      int S, I, R, V, Q ;  // parameters that define the world in a specific day (Q=1 :quarantine on, =0 :off)
      std::vector<std::vector<Cell>> m_grid{} ; 

    public:
      World(int L, int Ii, std::vector<std::vector<Cell>> initial_grid) ;

      std::vector<std::vector<Cell>> get_grid() ;

      double get_L() ;

      int get_S() ;

      int get_I() ;

      int get_R() ;

      int get_V() ;

      int HowManyCloseInfected(int i, int j) ;    // tells how many infetcted cells one have around (use to determine the infectione of a cell)

      void vaccine() ;    // vaccines a sucettible cell (turns 's' into 'r')

      void quarantine(double& beta) ;   // halves beta during quarantine

      void day(double& beta, double const& gamma, bool vax, bool quarantine, bool v_start ) ;   // changes the parameters of a day to create the following one

      void  draw_grid() ;   // draws the word in a specific day
  } ;

std::vector<Point> vector_cs(int L, std::vector<std::vector<Cell>> grid) ;    // contains the posotions of 's' cells

void CheckInput(double& T, double& L, double const& beta, double const& gamma,
                double const& initial_infected) ;   // checks if user's imputs have valid arguments

void Launch() ;   // intro

#endif
