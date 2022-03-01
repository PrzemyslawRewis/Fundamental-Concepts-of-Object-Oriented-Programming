#include "MapDist.h"

using namespace std;


MapDist::MapDist(const MapPoint &p1,const MapPoint &p2)
{
    distancelongitude=fabs(p2.longitude-p1.longitude);
    distancelatitude=fabs(p2.latitude-p1.latitude);
}
double MapDist::getlongitude() const
{
    return this->distancelongitude;
}
double MapDist::getlatitude() const
{
    return this->distancelatitude;

}

double MapDist::angularDistance() const
{
    return sqrt(distancelongitude*distancelongitude+distancelatitude*distancelatitude);
}


const MapDist distance(const MapPoint& p1,const MapPoint& p2)
{
    return MapDist (p1,p2);

}
