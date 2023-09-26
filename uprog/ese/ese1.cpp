// ese

#include <iostream>
#include <cstdlib> // libreria che contiene rand() e srand()
using namespace std ;

int main()  {   cout <<'\n' <<"Dimmi quale numero è piu grande tra i seguenti..." <<'\n' ;
                srand(time(NULL)) ;     // srand(seed) inizializza la sorgente (seed) di numeri casuali; time(NULL)=secondi dal 1/1/1970 ad ora

                int n1=rand()%100+1 ;   // rand()%100+1 genera un numero random da 1 a 99+1=100
                int n2=rand()%100+1 ;
                cout <<n1 <<", " <<n2 <<'\n' <<'\n' <<"scrivi: " ;

                int n3 ;
                cin >> n3 ;

                if (n1>n2)      {       if(n3==n1)      { cout <<'\n' <<"VAI PAPA!" <<'\n' <<'\n' ; }       // se rispondi bene dice ""
                                                else    {   if(n3==n2)      { cout <<'\n' <<"... e bravu u cugghiuni" <<'\n' <<'\n' ; }    // se rispondi male dice ""
                                                                else    { cout <<'\n' <<"ma sai leggere?..." <<'\n' <<'\n' ; }        // se rispondi a caso dice ""
                                                        }
                                }
                    else        { if(n3==n2)    { cout <<'\n' <<"VAI PAPA!" <<'\n' <<'\n' ; }
                                        else    {       if(n3==n1)      { cout <<'\n' <<"... e bravu u cugghiuni" <<'\n' <<'\n' ; }
                                                                else    { cout <<'\n' <<"ma sai leggere?..." <<'\n' <<'\n' ; } }
                                }

            }
