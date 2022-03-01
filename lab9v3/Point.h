#include <iostream>

using namespace std;


/*klasa reprezentujaca punkt*/
class Point
{
    public:
    static int number;
    /*konsturuktor bezparametrowy*/
    Point();
    /*konsturktor parametrowy @param s1- nazwa punktu @param x dlugosc @param y szerokosc*/
    Point(string s1,double x,double y);
    /*konsturktor kopiujacy*/
    Point(const Point& obj);
    /*konstruktor przenoszacy*/
    Point(Point&& obj);
    /*konstruktor nazwany ustawia współrzędne (x,y)*/
    static Point setPoint(double x,double y);
    /*konstruktor nazwany ustawia współrzędne na przeciwne (-x,-y)*/
    static Point setContrary(double x,double y);
    /*destruktor*/
    ~Point();
    /*metoda wypisujaca*/
    void fullPrint() const;
    
    /* */
    Point newMoved(string s1,double x,double y);
    /*metoda do zamiany nazwy @param s1 nowa nazwa*/
    void changeName(string s1);

    private:
    string _nazwa;
    double _dlugosc;
    double _szerokosc;
    int _numerobiektu;

};