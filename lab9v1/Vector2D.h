#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include <utility>

/**klasa wektora
* 
*/
class Vector2D{
    public:

        /** zmienna przechowująca ilość obiektów
          */
        static int count;

        /** konstruktor wektora
          * @param nazwa
          * @param pierwsza wspułżedna
          * @param druga wspułżedna
          */
        explicit Vector2D(std::string nazwa="Vx") : _nazwa(nazwa), _x(0.0), _y(0.0), _id(++count){}

        /** destruktor
          */
        ~Vector2D(){count--;}

        /** konstruktor nazwany wektora wspułżędne kartezjańskie
          * @param nazwa
          * @param pierwsza wspułżedna
          * @param druga wspułżedna
          */
        static Vector2D fromCarthesian(std::string name, double x, double y);

        /** konstruktor nazwany wektora wspułżędne kartezjańskie bez nazwy
          * @param pierwsza wspułżedna 
          * @param druga wspułżedna
          */
        static Vector2D fromCarthesian(double x, double y);

        /** konstruktor nazwany wektora wspułżędne biegunowe
          * @param nazwa
          * @param odległość od środka
          * @param kąt
          */
        static Vector2D fromPolar (std::string name, double r, double phi);
        
        /** konstruktor kopiujący
          */
        Vector2D(const Vector2D &vector); //kopiujacy
        
        /** konstruktor przenoszący
          */
        Vector2D(Vector2D &&vector);        //przenoszacy
        
        /** funkcja wypisująca wektora
          * 
          */
        void print() const;

        /**iloczyn skalarny
          * @return iloczyn skalarny
          */
        double dot(const Vector2D &vector) const;

        /** dodawanie wektorów
          */
        Vector2D add(const Vector2D &vector) const;

    private:
        std::string _nazwa;
        double _x;
        double _y;
        int _id;
};