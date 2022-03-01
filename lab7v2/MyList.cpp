#include "Element.h"
#include "MyList.h"

using namespace std;

MyList::MyList()
{
  head=nullptr;
  tail=nullptr;
  nazwa=nullptr;

}
MyList::MyList(const char* s1)
{
  head=nullptr;
  tail=nullptr;
  int rozmiar=strlen(s1);
  nazwa=new char[rozmiar+1];
  strcpy(nazwa, s1);
}
void MyList::append(const char* s1)
{
  Element *e1=new Element(s1);
  if(isEmpty())
  {
    head=tail=e1;
  }
  else
  {
    tail->next=e1;
    tail=e1;
  }
}
void MyList::append(Element* e1)
{
  if(isEmpty())
  {
    head=tail=e1;
  }
  else
  {
    tail->next=e1;
    tail=e1;
  }
}
Element* MyList::getHead() const
{
  return this->head;
}
Element* MyList::getLast() const
{
  return this->tail;
}
bool MyList::isEmpty() const
{
  return (head==nullptr)? true : false;
}
void MyList::removeFirst()
{
  if(!isEmpty())
  {
    Element* last=head;
    head=head->next;
    delete last;
    last=nullptr;
  }
  

}
char* MyList::getName() const
{
  return this->nazwa;
}
void MyList::clearList()
{
  while(!isEmpty())
      this->removeFirst();

}
void print(const MyList* l1)
{
  cout<<l1->getName()<<" = [";
  Element* last=l1->getHead();
  while(last!=nullptr)
  {
    cout<<last->getName();
    
    if(last->getNext()!=nullptr)
    {
      cout<<" ";
    }
    last=last->getNext();
  }
  cout<<"]"<<endl;
  
  
}
MyList::~MyList()
{
  cout<<"Destruktor MyList: "<<this->getName()<<endl;
  if(nazwa)
  {
    delete []nazwa;
    nazwa=nullptr;
  }
  delete head;
  
}