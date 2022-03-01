#include "Zespolone.h"

using namespace std;
using zespolone::Zespolone;
void Zespolone::Print(string s1)
{
    if(_im!=0.0)
        cout<<s1<<_re<<"+"<<_im<<"i"<<endl;
    else
        cout<<s1<<_re<<endl;
}
Zespolone zespolone::Dodaj(const Zespolone& w1,const Zespolone &w2)
{
    return Zespolone(w1.Re()+w2.Re(),w1.Im()+w2.Im());

}
