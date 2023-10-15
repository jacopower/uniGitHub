// 2cell.hpp

#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <iomanip>
#include <typeinfo>

using grid_t = std::vector<std::vector<Cell>> ;

enum class Cell : char { s, i, r } ;

struct Point { int a, b ; } ;

class World {
    private:
      int L_0 ;         // grid side length 
      int S, I_0, R, V, Q , D;  // parameters that define the world in a specific day (Q=1 :quarantine on, =0 :off)
      grid_t grid_0{} ; 

    public:
      World(int L, int I, grid_t initial_grid) ;   // initializes a word on day 0

      grid_t get_grid() ;   // separate functions or methods that show private info to the ones that modify private info, to prevent changing them unintentionally

      int get_L() ;    

      int get_S() ;

      int get_I() ;

      int get_R() ;

      int get_V() ;

      void setWorld(std::vector<Point> possible_cells) ;

      int HowManyCloseInfected(int i, int j) ;    // tells how many infetcted cells one have around (use to determine the infectione of a cell)

      void vaccine() ;    // vaccines a sucettible cell (turns 's' into 'r')

      void quarantine(double& beta) ;   // halves beta during quarantine

      void draw_grid() ;    // draws the word in a specific day
      
      void day(double& beta, double const& gamma, bool vax, bool quarantine, bool v_start ) ;   // changes the parameters of a day to create the following one
} ;

std::vector<Point> position_s(int L, grid_t grid) ;    // contains the position of 's' cells

void CheckInput(double& T, double& L, double const& beta, double const& gamma,
                double const& initial_infected) ;   // checks if user's imputs have valid arguments

void Intro() ;   // prints an intro

#endif
