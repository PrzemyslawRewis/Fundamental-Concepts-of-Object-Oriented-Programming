#include "MapDist.h"
using namespace std;

MapDist::MapDist(MapPoint p1,MapPoint p2)
{
    longdistance=p1.longitude-p2.longitude;
    latidistance=p1.latitude-p2.latitude;

}

double MapDist::getlongitude() const
{
    return this->longdistance;

}
double MapDist::getlatitude() const
{  
    return this->latidistance;
}
double MapDist::angularDistance() const
{
    return sqrt(pow(this->getlongitude(),2)+pow(this->getlatitude(),2));

}

MapDist distance(MapPoint p1,MapPoint p2)
{
    return MapDist(p1,p2);
    
}