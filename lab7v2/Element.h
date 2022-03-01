#pragma once
#include <iostream>
#include <cstring>

using namespace std;

//klasa reprezentujaca liste
class MyList;
//klasa reprezentujaca Element listy zawiera wskaznik na nastepny Element i dane 
class Element
{
  friend class MyList;
  public:
  //konstruktor domyslny
  Element();
  //konstruktor przyjmujacy argument const char *
  Element(const char* s1);
  //metoda zwracajaca atrybut name 
  char* getName();
  //metoda wypisujaca zawartosc atrybutu name
  void printName() const;
  //destruktor 
  ~Element();
  // metoda zwracajaca nastepny Element
  Element* getNext();

  private:
  char * name;
  Element *next;

};

