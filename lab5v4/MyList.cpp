#include "MyList.h"

using namespace std;

Node* new_node(const char *s1)
{
    Node * n1=new Node();
    n1->next=nullptr;
    n1->data=new char[strlen(s1)+1];
    strcpy(n1->data,s1);
    return n1;

}
void init(MyList* l1, const char * s1)
{
    l1->head=nullptr;
    l1->nazwa=new char[strlen(s1)+1];
    strcpy(l1->nazwa,s1);

}
void append(MyList* l1, const char *s1)
{
    Node* lst=new_node(s1);
    if(l1->head==nullptr)
    {
        l1->head=lst;
        
    }
    else
    {
        Node * last=l1->head;
        lst->next=last;
        l1->head=lst;
       
    }

}
bool empty(const MyList* l1)
{
    if(l1->head==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}
void print(const MyList* l1)
{
    if(l1->head==nullptr)
    {
        return;
    }
    cout<<l1->nazwa<<": ";
    Node * last=l1->head;
    while(last!=nullptr)
    {
        cout<<last->data<<" ";
        last=last->next;
    }
    cout<<"\n";



}

void replace(MyList* l1,const char *s1,const char *s2)
{
    
        Node * last=l1->head;
        while(last!=nullptr)
            {
                if(strcmp(last->data,s1)==0)
                {
                    delete [] last->data;
                    last->data=new char[strlen(s2)+1];
                    strcpy(last->data,s2);
                    break;
                }
                else
                    last=last->next;
            }

}


void insertAfter(MyList* l1,const char *s1,const char *s2)
{

}
void removeAfter(MyList* l1,const char *s1)
{

}
void remove(MyList* l1,const char *s1)
{

}
void clear(MyList* l1)
{
    
    delete[] l1->nazwa;
    l1->nazwa=nullptr;
    Node * last=l1->head;
    if(last!=nullptr)
    {
        while(last)
        {
            Node* last2=last->next;
            delete[] last->data;
            last->data=nullptr;
            delete last;
            last=nullptr;
            last=last2;

        }
        l1->head=nullptr;
    }  

}
