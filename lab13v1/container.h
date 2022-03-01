#pragma once
#include <iostream>
using namespace std;

class Container;
const int MEM_MAX=100;

class Container
{
    public:
    Container() : _var(0) {}
    Container(int val) : _var(val) { cout<<"Container(int) "<<val<<endl; }

    int &value();

    void *operator new(size_t);
    void operator delete(void *);
    void *operator new[](size_t);
    void operator delete[](void *);

    
    static Container *mem_ptr;
    static int mem_size;
    private:
    int _var;
};