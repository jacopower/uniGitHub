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
      int m_L ;         // lato griglia
      int S, I, R, V, Q ;  // numeri susc, infetti, morti/guariti, vaccinati
      std::vector<std::vector<Cell>> m_grid{} ; 

    public:
      World(int L, int Ii, std::vector<std::vector<Cell>> initial_grid) ;

      std::vector<std::vector<Cell>> get_grid() ;

      double get_L() ;

      int get_S() ;

      int get_I() ;

      int get_R() ;

      int get_V() ;

      int HowManyCloseInfected(int i, int j) ;

      void vaccine() ;

      void quarantine(double& beta) ;

      void day(double& beta, double const& gamma, bool vax, bool quarantine, bool v_start ) ;

      void  draw_grid() ;
  } ;

std::vector<Point> vector_cs(int L, std::vector<std::vector<Cell>> grid) ;

void CheckInput(double& T, double& L, double const& beta, double const& gamma,
                double const& initial_infected) ;

void Launch() ;

#endif
