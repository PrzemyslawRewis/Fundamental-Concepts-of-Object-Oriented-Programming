#include "MapPoint.h"

using namespace std;

MapPoint* construct(const char* n,double d,double s)
{
    MapPoint *m1=(MapPoint*)malloc(sizeof(MapPoint));
    if(d>0)
    {
        m1->polkula1='E';

    }
    else
    {
        m1->polkula1='W';

    }
        

     if(s>0)
    {
        m1->polkula2='N';

    }
    else
    {
        m1->polkula2='S';

    }
    m1->dlugosc=d;
    m1->szerokosc=s;
    m1->nazwa=(char*)malloc(strlen(n)+1);
    strcpy(m1->nazwa,n);
    return m1;
    

}
MapPoint*  construct(const char* n,double d,char k1,double s,char k2)
{
    MapPoint *m1=(MapPoint*)malloc(sizeof(MapPoint));
    m1->polkula1=k1;
    m1->polkula2=k2;
    m1->nazwa=(char*)malloc(strlen(n)+1);
    
    if(k1=='E')
    {
        m1->dlugosc=d;

    }
    else
    {
        m1->dlugosc=-d;

    }
        

    if(k2=='N')
    {
        m1->szerokosc=s;

    }
    else
    {
        m1->szerokosc=-s;

    }
    strcpy(m1->nazwa,n);
    return m1;
  

}
void print(const MapPoint* m1)
{
    
    cout<<"Wspolrzedne dla "<<m1->nazwa<<": "<<abs(m1->dlugosc)<<m1->polkula1<<", "<<abs(m1->szerokosc)<<m1->polkula2<<"\n";

}
void movePoint (MapPoint* m1, const double shft1,const double shft2)
{
    m1->dlugosc+=shft1;
    m1->szerokosc+=shft2;
    if(m1->dlugosc>0)
    {
        m1->polkula1='E';

    }
    else
    {
        m1->polkula1='W';

    }
        

     if(m1->szerokosc>0)
    {
        m1->polkula2='N';

    }
    else
    {
        m1->polkula2='S';

    }
    
}
void clear(MapPoint* m1)
{
    cout<<"Usuwanie "<<m1->nazwa<<endl;
    free(m1->nazwa);
    m1->nazwa=NULL;
    free(m1);
    m1=NULL;
}
void clear(MapPoint* m1,MapPoint* m2,MapPoint* m3)
{
    cout<<"Usuwanie "<<m1->nazwa<<endl;
    free(m1->nazwa);
    m1->nazwa=NULL;
    free(m1);
    m1=NULL;
    cout<<"Usuwanie "<<m2->nazwa<<endl;
    free(m2->nazwa);
    m2->nazwa=NULL;
    free(m2);
    m2=NULL;
    cout<<"Usuwanie "<<m3->nazwa<<endl;
    free(m3->nazwa);
    m3->nazwa=NULL;
    free(m3);
    m3=NULL;
}
char* getName(const MapPoint m1)
{
    return m1.nazwa;
}