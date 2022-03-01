#include <iostream>
#include <cmath>

using namespace std;

class Vector2D
{

    public:

        Vector2D() {++Vector2D::count;};
        Vector2D(string s1):nazwa(s1),wsp1(0.0),wsp2(0.0){++Vector2D::count;};
        Vector2D(double a,double b,string s1="Vx"):nazwa(s1),wsp1(a),wsp2(b){++Vector2D::count;};
        Vector2D(const Vector2D& obj);
        Vector2D(Vector2D&& obj);
        static Vector2D fromCarthesian(string s1,double x1,double x2);
        static const Vector2D fromPolar(string s1,double x1,double x2);
        void print(string s1=" ") const;
        double dot(const Vector2D& obj) const;
        Vector2D add(const Vector2D& obj) const;
        static int count;
        static Vector2D fromCarthesian(double x,double y);
        ~Vector2D();


    private:
        string nazwa="Vx";
        double wsp1;
        double wsp2;

};

