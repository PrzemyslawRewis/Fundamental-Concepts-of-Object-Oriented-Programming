#include "Zespolone.h"

using namespace std;
void Zespolone::Print(string s1)
{
    if(_im!=0.0)
        cout<<s1<<_re<<"+"<<_im<<"i"<<endl;
    else
        cout<<s1<<_re<<endl;
}
double Zespolone::Im()
{
    return _im;
}
Zespolone Dodaj(const Zespolone& w1,const Zespolone &w2)
{
    return Zespolone(w1._re+w2._re,w1._im+w2._im);

}
