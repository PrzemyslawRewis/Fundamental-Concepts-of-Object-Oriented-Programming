#pragma once
#include <iostream>
#include <cstring>

using namespace std;

struct  Node
{
    char * data;
    Node * next;
   
};

struct MyList
{
    Node* head;
};
void init(MyList* l1);
Node* new_node(const char *s1);
void add(MyList* l1,const char * str);
void insertAfter(const MyList *l1,const char * str1,const char * str2);
void print(const MyList *l1);
void clear(MyList *l1);
bool empty(const MyList *l1);
Node* last(const MyList *l1);
Node* find(const MyList *l1,const char *);