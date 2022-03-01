#pragma once
#include <iostream>
#include <cstring>
#include "Element.h"
using namespace std;

class MyList;
//funkcja wypisujaca liste
void print(const MyList* l1);
//klasa reprezentujaca liste zawierajaca wskanik na Element head tail i nazwa 
class MyList
{
  friend void print(const MyList* l1); 
  public:
  //konstruktor domyslny
  MyList();
  //konstruktor przyjmujacy argument const char*
  MyList(const char* s1);
  //metoda dodajaca element na koniec
  void append(const char* s1);
  //metoda dodajaca Element na koniec
  void append(Element* e1);
  // metoda zawierajaca atrybut head
  Element* getHead() const;
  // metoda zawierajaca atrybut last
  Element* getLast() const;
  //metoda sprawdzajaca czy lista jest pusta
  bool isEmpty() const;
  //metoda usuwajaca pierwszy element z listy
  void removeFirst();
  //metoda zwaracajaca atrybut nazwa
  char* getName() const ;
  //metoda czyszczaca liste
  void clearList();
  //desturktor obiektu lista
  ~MyList(); 


  private:
  Element* head;
  Element* tail;
  char* nazwa;

};
