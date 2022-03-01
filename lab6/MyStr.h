#pragma once
#include "MyList.h"

using namespace std;

struct MyString
{
    char * dane;
    char * begin;
    char * end;
    char * next;
    char * separatory;
};

char * mycopy(const char * s1);
int mystrlen(const char* s1);
bool findSep(const char znak,const char* text1);
void initMyString(MyString* s1,const char* text1, const char* separatators=NULL); 
char* mystrtok(MyString*);
char * mystrcat (const char * s1, const char * text,char sep1='\0');
void addSep(MyString* s1, const char* separatators);
void split2list(MyList *l1, MyString* s1);
char * gettok(MyString* s1,int i);
void removeMyString(MyString* s1);