// ese4

#include <iostream>
#include <cmath>
#include <iomanip> //for the function setprecision()

using std::cout ;
using std::cin ;
using std::pow ;
using std::setprecision ;

double solvex(double a, double b)   {   double x ;
                                        x =(-b)*(1/a) ;

                                        return x ;
                                    }

double perim(int sides, double s_lenght)    {   double perimeter ;
                                                perimeter = sides * s_lenght ;

                                                return perimeter ;
                                            }

double c_a(int sides)   {   double c ;

                            switch(sides)   {   default:    c = 0 ;
                                                            break ;
                                                case 3:     c = 0.289 ;
                                                            break ;
                                                case 4:     c = 0.5 ;
                                                            break ;
                                                case 5:     c = 0.688 ;
                                                            break ;
                                                case 6:     c = 0.866 ;
                                                            break ;
                                                case 7:     c = 1.038 ;
                                                            break ;
                                                case 8:     c = 1.207 ;
                                                            break ;
                                                case 9:     c = 1.374 ;
                                                            break ;
                                                case 10:    c = 1.539 ;
                                                            break ;
                                                case 12:    c = 1.866 ;
                                                            break ;
                                            }

                            return c ;
                        }

double area(int sides, double s_lenght) {   double area ;
                                            area = perim(sides, s_lenght)*s_lenght*c_a(sides)*0.5 ;

                                            return area ;
                                        }

//double 3darea(int sides; double s_lenght) {;}

double volume_r(int sides, double s_lenght, double h)   {   double volume ;
                                                            volume = area(sides, s_lenght)*h ;

                                                            return volume ;
                                                        }

double pi() {   double p =0 ;
                double i =0 ;
                double x =0 ;
                long double const dx =0.00000001 ;
                while (x<=1)    {   i += 4*(1/(1+pow(x, 2)))*dx ;
                                    x += dx ;
                                }
                p=i ;
                return p ;
            }

int main()  {   cout <<'\n' <<'\n' ;
                cout <<"Today I feel strong, and i will compute for you some math problems..." <<'\n' <<'\n' ;

                cout <<"First i will solve for x the equation: ax + b = 0" <<'\n' ;
                cout <<"give me 'a': " ;
                double a ;
                cin >> a ;
                cout <<"give me 'b': " ;
                double b ;
                cin >> b ;
                cout <<"x is: " <<solvex(a, b) <<'\n' <<'\n' ;

                cout <<"Now choose a 2d or 3d geometric (regular) shape and i will calculate some data about it..." <<'\n' ;
                cout <<"how many dimentions dose il have?[2 or 3] " ;
                int d ;
                cin >> d ;
                while (d!=2 && d!=3)    {   cout <<"[2 or 3] " ;
                                            cin >> d ;
                                        }
                if (d==2)   {   cout <<"how many sides does it have? " ;
                                int sides2 ;
                                cin >>sides2 ;
                                cout <<"how long is each side? " ;
                                double lenght2 ; 
                                cin >>lenght2 ;
                                cout <<"ok, the perimeter of your shape is: " <<perim(sides2, lenght2) ;
                                cout <<"; and the area is: " <<area(sides2, lenght2) <<'\n' <<'\n' ;
                            }
                else if (d==3)  {   cout <<"how many sides does the base have? " ;
                                    int sides3 ;
                                    cin >> sides3 ;
                                    cout <<"how long is each side? " ;
                                    double lenght3 ; 
                                    cin >>lenght3 ;
                                    cout <<"how long is the hight? " ;
                                    double h ;
                                    cin >>h ;
                                    cout <<"ok, the volume of your shape is: " <<volume_r(sides3, lenght3, h) <<'\n' <<'\n' ;
                                }

                cout <<"Do you want to know the value of pi?" <<'\n' ;
                cout <<"[y or n] " ;
                char r ;
                cin >> r ;
                while (r!='y')  {   cout <<"are you ure you don't want to know?... " ;
                                    cin >>r ;
                                }
                if (r=='y')   { cout <<"pi is: " <<setprecision(7) <<pi() <<'\n' <<'\n' ; }
                
            }
