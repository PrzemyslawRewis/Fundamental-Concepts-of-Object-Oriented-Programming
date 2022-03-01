#pragma once
#include <iostream>
#include <cstring>
using namespace std;
//struktura reprezentujaca wezel w liscie przechowujacy napis oraz wskaznik na nastepny element
struct Node
{
    char* data;
    Node *next;
    

};
//struktura reprezentujaca liste jednokierunkowa 
struct MyList
{
    Node *head;

};
//funkcja incjalizujaca liste o podanej nazwie
void init(MyList* l1);
//funkcja dodajaca element na poczatek listy
void append(MyList* l1, const char *s1);
//funkcja sprawdzajaca czy lista jest pusta
bool empty(const MyList* l1);
//funkcja wypisujaca liste
void print(const MyList* l1);
//funkcja zamieniajaca dane s1 na s2 w wezle
void replace(MyList* l1,const char *s1,const char *s2);
//funkcja wstawiajaca wezel po danym wezle
void insertAfter(MyList* l1,const char *s1,const char *s2);
//funkcja usuwajaca wezel po danym wezle
void removeAfter(MyList* l1,const char *s1);
//funkcja kasujaca okreslona zawartosc
void remove(MyList* l1,const char *s1);
//funkcja czszczaca liste
void clear(MyList* l1);
//funkcja towrzaca nowy wezel dla danego napisu
Node* new_node(const char *s1);

void removeFirst(MyList *l1);