#include "studList.h"
using namespace std;

Element::Element()
{
    this->dane=nullptr;
    this->next=nullptr;
}
Element::Element(const char* s1)
{
    int size=strlen(s1);
    this->dane=new char[size+1];
    strcpy(this->dane,s1);
    this->next=nullptr;

}
char* Element::getName()
{
    return this->dane;
}

void Element::printName()
{
    cout<<this->dane;

}
Element* Element::getNext()
{
    return this->next;

}
Element::~Element()
{
    cout<<"Destruktor Element: kasowanie "<<this->dane<<endl;
    delete [] dane;
    dane=nullptr;
 
}
StudList::StudList()
{
    this->head=nullptr;
    this->tail=nullptr;
    this->nazwa=nullptr;

}
StudList::StudList(const char *s1)
{
    int rozmiar=strlen(s1);
    this->head=nullptr;
    this->tail=nullptr;
    this->nazwa=new char[rozmiar+1];
    strcpy(this->nazwa,s1);

}
void StudList::print() const
{
    if(!this->isEmpty())
    {
        cout<<this->nazwa<<" = "<<"[";
        Element* last=this->head;
        while(last!=this->tail)
        {
            cout<<last->dane<<" ";
         last=last->next;
        }
    cout<<this->tail->dane<<"]"<<endl;

    }
    else
    {
        cout<<this->nazwa<<" = "<<"[]"<<endl;
    }
    

}
void StudList::clearList()
{
  if(!this->isEmpty())
  {
    while(head!=tail)
    {
        Element* last =head;
        head=last->next;
        delete last;
        last=nullptr;
    }
    delete tail;
    tail=nullptr;
    head=nullptr;
  } 


}
void StudList::prepend(Element* el1)
{
    
    if(this->head==nullptr)
    {
        this->head=el1;
        this->tail=el1;
        
    }
    else
    {
        Element * last=this->head;
        el1->next=last;
        this->head=el1;
       
    }
    

}
void StudList::prepend(const char* s1)
{
    Element* lst= new Element(s1);
    if(this->head==nullptr)
    {
        this->head=lst;
        this->tail=this->head;
        
    }
    else
    {
        Element * last=this->head;
        lst->next=last;
        this->head=lst;
       
    }

}
void StudList::removeLast()
{  
     if(head)
     {
      if(tail==head)
      {
          delete tail;
          head=tail=nullptr;
      }
      else
      {
          Element *wsk=head;
          while(wsk->next!=tail)
          {
            wsk=wsk->next;
          }
          delete tail;
          wsk->next=nullptr;
          tail=wsk;

      }
  }
   

}
Element* StudList::getLast()
{
    Element *wsk=tail;

    if(head==tail){

        head=tail=nullptr;

    }else{

        Element *wsk1=head;

        while(wsk1->next!=tail){
          wsk1=wsk1->next;
        }

        wsk1->next=nullptr;
        tail=wsk1;

    }

  return wsk;
}
char* StudList::getName() const
{
    return this->nazwa;

}
Element* StudList::getHead()
{
    return this->head;
}
Element* StudList::getTail()
{
    return this->tail;

}
bool StudList::isEmpty() const
{
    return (this->head==nullptr) ? true : false;

}
StudList::~StudList()
{
    cout<<"Destruktor StudList: "<<this->nazwa<<endl;
    delete [] nazwa;
    nazwa = nullptr;
   
}
