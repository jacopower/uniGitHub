// ese5

#include <iostream>

using std::cout ;
using std::cin ;

char Aa(char a) {   switch(a)   {   case 'A':     a ='a' ;
                                                break ;
                                    case 'B':     a ='b' ;
                                                break ;
                                    case 'C':     a ='c' ;
                                                break ;
                                    case 'D':     a ='d' ;
                                                break ;
                                    case 'E':     a ='e' ;
                                                break ;
                                    case 'F':     a ='f' ;
                                                break ;
                                    case 'G':     a ='g' ;
                                                break ;
                                    case 'H':     a ='h' ;
                                                break ;
                                    case 'I':     a ='i' ;
                                                break ;
                                    case 'J':     a ='j' ;
                                                break ;
                                    case 'K':     a ='k' ;
                                                break ;
                                    case 'L':     a ='l' ;
                                                break ;
                                    case 'M':     a ='m' ;
                                                break ;
                                    case 'N':     a ='n' ;
                                                break ;
                                    case 'O':     a ='o' ;
                                                break ;
                                    case 'P':     a ='p' ;
                                                break ;
                                    case 'Q':     a ='q' ;
                                                break ;
                                    case 'R':     a ='r' ;
                                                break ;
                                    case 'S':     a ='s' ;
                                                break ;
                                    case 'T':     a ='t' ;
                                                break ;
                                    case 'U':     a ='u' ;
                                                break ;
                                    case 'V':     a ='v' ;
                                                break ;
                                    case 'W':     a ='w' ;
                                                break ;
                                    case 'X':     a ='x' ;
                                                break ;
                                    case 'Y':     a ='y' ;
                                                break ;
                                    case 'Z':     a ='z' ;
                                                break ;
                                }
                    return a ;
                }

double operate(double n1, double n2, char op)   {   int result ;
                                                    switch(op)  {   case '+':   result =n1+n2 ;
                                                                            break ;
                                                                case '-':   result =n1-n2 ;
                                                                            break ;
                                                                case '*':   result =n1*n2 ;
                                                                            break ;
                                                                case '/':   result =n1/n2 ;
                                                                            break ;
                                                                default:    result =0 ;
                                                                            break ;
                                                            }
                                                    return result ;
                                                }

int main()  {   cout <<'\n' <<"Hi, write a character: " ;
                char a ;
                cin >> a ;
                cout << Aa(a) <<'\n' <<'\n' ;

                cout <<"now i will make an operaion between two numbers..." <<'\n' ;
                cout <<"give me n1: " ;
                double n1 ;
                cin >>n1 ;
                cout <<"give me n2: " ;
                double n2 ;
                cin >>n2 ;
                cout <<"now give me an operator [+ or - or * or /] " ;
                char op ;
                cin >>op ;
                cout <<"here is the result: " <<operate(n1, n2 ,op) <<'\n' <<'\n' ;
            }
