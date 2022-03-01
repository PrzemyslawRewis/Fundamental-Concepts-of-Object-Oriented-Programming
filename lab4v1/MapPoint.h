#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


struct MapPoint
{
    char * nazwa;
    double dlugosc;
    double szerokosc;
    char polkula1;
    char polkula2;


};

MapPoint*  construct(const char* n,const double d,const double s);
MapPoint*  construct(const char* n,double d,char k1,double s,char k2);
void print(const MapPoint* m1);
void movePoint (MapPoint* m1, const double shft1,const double shft2);
void clear(MapPoint* m1);
void clear(MapPoint* m1,MapPoint* m2,MapPoint* m3);
char * getName(const MapPoint m1);