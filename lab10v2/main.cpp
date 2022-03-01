/*
 Celem zadania jest przećwiczenie konwersji jawnych i niejawnych oraz jak im zapobiegać.
 Prosze zdefiniować klasy Wymierne i Zespolone (re i im), reprezentujące odpowiednio  liczby wymierne (licznik/mianownik) oraz zespolone (Re, Im)

 UWAGA!!!
 W zadaniu trzeba zdefiniować zarowno konstruktory jak i operotory konwertujace.
 Konstruktory z listami inicjalizacyjnymi  (inline) można zdefiniowac w pliku nagłówkowym.
 Za brak konstruktorów przenoszących będą odejmowane punkty.

 Blok ERROR ma się nie kompilować i zgłaszać dwa błędy - sprawdz: make error albo odkomentuj linię #define ERROR (za brak -1.5 pkt)
 Proszę nie zapomnieć o dokumentacji doxygen
*/

// Po wywołaniu make error albo odkomentowaniu tej linii powinny pokawić się dwa błedy
//  #define ERROR

#include <iostream>
#include <math.h>
#include "Wymierne.h"
#include "Zespolone.h"

int main() {

  std::cout << "\n*** WYMIERNE ***"<< std::endl;
  
  Wymierne Raz(1, 2), Dwa(3, 4), Trzy;
  Raz.Print("Raz = ");
  Dwa.Print("Dwa = ");
  Trzy.Print("Trzy = ");

  Wymierne W1 = Wymierne::Pomnoz(Raz, Dwa);
  W1.Print("W1 = ");
  double L1 = W1;
  std::cout<< L1 << std::endl;

  Wymierne W2 = Wymierne::Pomnoz(Raz, static_cast<Wymierne>(5));
  W2.Print("W2 = ");

  Wymierne W3 = Wymierne::Pomnoz(static_cast<Wymierne>(10), static_cast<Wymierne>(5));
  W3.Print("W3 = ");

  double L2 = sqrt(W3);
  std::cout<< L2 << std::endl;

  Dodaj(Raz,Dwa).Print("Raz+Dwa = ");
  Dodaj(static_cast<Wymierne>(2),Wymierne(3)).Print("2+3 = ");

  std::cout << "\n*** ZESPOLONE ***"<< std::endl;

  Zespolone Z1 = Dodaj(Zespolone(1, 5), static_cast<Zespolone>(4));Z1.Print("Z1=");

  Zespolone Z2 = Dodaj(Zespolone(1, 5), static_cast<Zespolone>(Dwa));              
  Z2.Print("Z2 = ");

  Zespolone Z3 = Dodaj(static_cast<Zespolone>(Wymierne(10, 3)), static_cast<Zespolone>(Wymierne(1, 3)));  
  Z3.Print("Z3 = ");
  
  Zespolone Z4 = Dodaj(1, 2);             
  Z4.Print("Z4 = ");

  Zespolone Z5(std::move(Z4));
  Z4.Print("Z4 = ");
  Dodaj(Z5,Z2).Print("Z5+Z2 = ");

  std::cout <<std::endl;
  
#ifdef ERROR
  Wymierne::Pomnoz(10, 5).Print("");
  Dodaj(Wymierne(10, 3), Zespolone(1, 3)).Print("");
#endif

  return 0;
}
/* Oczekiwany wynik:

*** WYMIERNE ***
Raz = 1/2
Dwa = 3/4
Trzy = 0
W1 = 3/8
0.375
W2 = 5/2
W3 = 50
7.07107
Raz+Dwa = 10/8
2+3 = 5

*** ZESPOLONE ***
Z1=(5,5)
Z2 = (1.75,5)
Z3 = (3.66667,0)
Z4 = (3,0)
Z4 = (0,0)
Z5+Z2 = (4.75,5)

*/

