#include <iostream>
#include <cstring>

using namespace std;

class Element
{
    friend class StudList;
    public:
        Element();
        Element(const char* s1);
        char * getName();
        void printName();
        Element* getNext();
        ~Element();
    private:
        char * dane;
        Element * next;

};
class StudList
{
    public:
        StudList();
        StudList(const char *s1);
        void print() const;
        void clearList();
        void prepend(const char* s1);
        void prepend(Element * e1);
        void removeLast();
        char* getName() const;
        Element* getHead();
        Element* getTail();
        bool isEmpty() const;
        Element* getLast();
        ~StudList();

    private:
        Element* head;
        Element* tail;
        char* nazwa;


};