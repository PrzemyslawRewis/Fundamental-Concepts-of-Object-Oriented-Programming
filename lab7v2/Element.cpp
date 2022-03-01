#include "Element.h"

using namespace std;
Element::Element()
{
  next=nullptr;
  name=nullptr;

}
Element::Element(const char* s1)
{
  next=nullptr;
  int rozmiar=strlen(s1);
  name=new char[rozmiar+1];
  strcpy(name, s1);

}
char* Element::getName()
{
  return this->name;

}
void Element::printName() const
{
  cout<<name;

}
Element* Element::getNext()
{
  return this->next;
}
Element::~Element()
{
  cout<<"Destruktor Element: "<<this->getName()<<endl;
  if(name)
  {
    delete [] name;
    name=nullptr;
  }
}
