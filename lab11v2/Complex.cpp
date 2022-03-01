#include "Complex.h"
#include "Vector.h"

using namespace std;

void Complex::print(string s1) const
{
    Complex *th = const_cast<Complex *>(this);
    th->licznik++;
    std::cout << "[Print " << licznik << "] ";
    if(_im!=0.0)
        cout<<s1<<_re<<" + "<<_im<<"i"<<endl;
    else
        cout<<s1<<_re<<endl;
}
double Complex::Im() const
{
    return _im;
}
double Complex::Re() const
{
    return _re;
}
Complex Complex::operator+(Complex const &obj)
{
  return Complex(this->_re+obj._re,this->_im+obj._im);
  
}
Complex& Complex::operator=(const Complex& obj)
{

  this->_re=obj._re;
  this->_im=obj._im;
  return *this;
  
}

