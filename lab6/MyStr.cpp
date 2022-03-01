#include "MyStr.h"
using namespace std;

int mystrlen(const char* s1)
{
    int ilosc;
    while(*s1!='\0')
    {
        ilosc++;
        s1++;
    }
    return ilosc-1;
    
}

char * mycopy(const char * s1)
{
    int rozmiar=mystrlen(s1);
    char * tab=new char[rozmiar+1];
    for(int i=0;i<=rozmiar;i++)
    {
        tab[i]=s1[i];

    }
    return tab;

}

bool findSep(const char znak,const char* text1)
{
    while(*text1!='\0')
    {
        if(*text1==znak)
        {
            return true;
            break;

        }
        else
            text1++;
    }
    return false;


}
void initMyString(MyString* s1,const char* text1, const char* separatators)
{
    s1->dane=mycopy(text1);
    s1->begin=s1->dane;
    s1->next=s1->begin;
    s1->end=s1->dane+mystrlen(s1->dane);
    if(separatators==nullptr)
        s1->separatory = nullptr;
    else s1->separatory = mycopy(separatators);

} 
char* mystrtok(MyString *split){
    char *str = split->next, *sep = split->separatory;

    while(*str=='\0' && str!=split->end)    //jezeli koniec lancucha ale nie jest to koniec calego napisu
        str++;
    
    char *w = str;
    bool find;

    while(w!=split->end){
        find = false;
        while(*sep!='\0'){
            if(*w==*sep || *w=='\0'){
                find = true;
                break;
            }
            else sep++;
        }
        if(find){
            split->next = w+1;
            break;
        }                                          
        sep = split->separatory;
        w++;
    }
    
    while(w!=split->end){
        find = true;
        while(*sep!='\0'){
            if(*w==*sep || *w=='\0'){
                find = false;
                break;
            }
            sep++;
        }
        if(!find){
            *w='\0';
            split->next = w+1;
        }
        else break;
        sep = split->separatory;
        w++;
    }

    if(w==split->end)
        split->next = split->end;

    return str;
}
char * mystrcat (const char * s1, const char * text,char sep1)
{
   return " ";

}
void addSep(MyString* s1, const char* separatators)
{
    if(s1->separatory == nullptr)
        s1->separatory = mycopy(separatators);
    else s1->separatory = mystrcat(s1->separatory, separatators);

}
void split2list(MyList *l1, MyString* s1)
{

}
char * gettok(MyString* s1,int i)
{
    return " ";

}

void removeMyString(MyString* s1)
{
    delete[] s1->dane;
    s1->dane=nullptr;
    delete s1->begin;
    s1->begin=nullptr;
    delete s1->end;
    s1->end=nullptr;
    delete[] s1->next;
    s1->next=nullptr;
    if(s1->separatory!=nullptr)
        delete[] s1->separatory;
    s1->separatory=nullptr;

}