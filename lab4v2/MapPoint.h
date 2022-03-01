#pragma once
#include <iostream>
#include <string>

using namespace std;


struct MapPoint
{
    string nazwa;
    double dlugosc;
    double szerokosc;
    char polkula1;
    char polkula2;


};

MapPoint*  construct(string n,const double d,const double s);
MapPoint*  construct(string n,double d,char k1,double s,char k2);
void print(const MapPoint* m1);
void movePoint (MapPoint* m1, const double shft1,const double shft2);
void clear(MapPoint* m1);
void clear(MapPoint* m1,MapPoint* m2,MapPoint* m3);
string getName(const MapPoint m1);