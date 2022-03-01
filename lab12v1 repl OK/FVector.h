#pragma once
#include "Fraction.h"
#include <vector>
#include <algorithm>

using namespace std;


class FVector
{
  friend std::ostream& operator<<(std::ostream& o,const FVector & obj);
  public:
  FVector(Fraction v1)
  {
    vec.push_back(v1);
  }
  void operator+=(Fraction v2)
  {
    vec.push_back(v2);
  }
  void sort()
  {
    std::sort(vec.begin(),vec.end());
  }
  private:
  std::vector<Fraction> vec;
  
  
};
std::ostream& operator<<(std::ostream& o,const FVector & obj)
{
  o<<"[";
  for (unsigned int i=0;i<obj.vec.size();i++)
  {
    o<<obj.vec[i]<<",";
  }
  o<<"]";
  o<<endl;
  return o; 
}