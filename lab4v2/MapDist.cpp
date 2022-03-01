#include "MapDist.h"

using namespace std;

const MapDist distance(MapPoint m1,MapPoint m2)
{
    MapDist d1;
    d1.longitude=abs(m2.dlugosc-m1.dlugosc);
    d1.latitude=abs(m2.szerokosc-m1.szerokosc);
    return d1;
    
}
double angularDistance(MapDist d)
{
    return sqrt(d.latitude*d.latitude+d.longitude*d.longitude);

}
const MapPoint& closestPlace(MapPoint* m1, MapPoint* m2,MapPoint* m3)
{
    MapDist d1=distance(*m1,*m2);
    MapDist d2=distance(*m1,*m3);

    if(angularDistance(d1)<angularDistance(d2))
        return *m2;
    else
        return *m3;    

}
MapPoint inTheMiddle(MapPoint* m1,MapPoint* m2,string name)
{
   
    MapPoint p1;
    p1.dlugosc=(m1->dlugosc+m2->dlugosc)/2.0;
    p1.szerokosc=(m1->szerokosc+m2->szerokosc)/2.0;
    if(p1.dlugosc>0)
    {
        p1.polkula1='E';

    }
    else
    {
        p1.polkula1='W';

    }
        

     if(p1.szerokosc>0)
    {
        p1.polkula2='N';

    }
    else
    {
        p1.polkula2='S';

    }
    p1.nazwa=name;
    return p1;


}  