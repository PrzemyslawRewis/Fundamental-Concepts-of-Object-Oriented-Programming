#include "MyList.h"

using namespace std;

void init(MyList* l1)
{
    l1->head=nullptr;

}
Node* new_node(const char *s1)
{
    Node* tmp=new Node;
    tmp->next=nullptr;
    tmp->data=new char[strlen(s1)+1];
    strcpy(tmp->data,s1);
    return tmp;
}
void add(MyList* l1,const char * str)
{
    Node* tmp=new_node(str);
    if(l1->head==nullptr)
    {
       l1->head=tmp;

    }
    else
    {
        Node * last=l1->head;
  
        while(last->next!=nullptr)
        {
            last=last->next;
        }
        last->next=tmp;


    }

}

void insertAfter(const MyList *l1,const char * str1,const char * str2)
{
  /*  Node * last=l1->head;
    Node* tmp=new_node(str);
    if(strcmp(head->data,str1)==0)
    {
       l1->head=tmp;

    }
    else
    {
        
  
        while(last->next!=nullptr)
        {
            if(strcmp(last->data,str1)==0)
            {
                Node tmp=new_node(str2);
                last->next=tmp;
                break;
            }
            else
            last=last->next;
        }


    }*/



}
void print(const MyList *l1)
{

    if(empty(l1))
        cout<<endl;
    else
    {

        
        Node * last=l1->head;
  
        while(last->next!=nullptr)
        {
            cout<<last->data<<" ";
            last=last->next;
        }
        cout<<last->data<<endl;
    }    


}
void clear(MyList *l1)
{
   while(l1->head==nullptr)
   {
        Node * last=l1->head;
  
        while(last->next!=nullptr)
        {
            cout<<last->data<<" ";
            last=last->next;
        }
        delete []last->data;
        delete las
       
   }
    
}
bool empty(const MyList *l1)
{
    if (l1->head==nullptr)
        return true;
    else
        return false;    

}
Node* last(const MyList *l1)
{

    if(empty(l1))
        return nullptr;
    else
    {

        Node * last=l1->head;
        while(last->next!=nullptr)
        {
            last=last->next;
        }
        return last;
    }    


}
Node* find(const MyList *l1,const char *)
{


}