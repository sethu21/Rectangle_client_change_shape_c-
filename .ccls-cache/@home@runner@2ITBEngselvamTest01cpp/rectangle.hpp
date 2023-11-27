#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "point.hpp"

using namespace std;

class Rectangle{
private:
    Point b_left;
    Point u_right;
public:
    Rectangle();

    
    Rectangle(int bx, int by, int ux, int uy);  

    
    Rectangle(const Point& bl, const Point& ur); // inicializaacijas konstr.

    const Point& bottom_left() const;
    const Point& upper_right() const;

    void set_bottom_left(const Point& bl);
    void set_upper_right(const Point& ur);

    int width() const;
    int height() const;
    double diagonal() const;
    int area() const;

    
    void move_rectangle(int dx, int dy);

    
    void stretch(int dx, int dy);

   
    void stretch(int dxy);

    
};

ostream& operator<<(ostream& os, const Rectangle& r);
istream& operator<<(istream& is,  Rectangle& r);

bool equalAreas(const Rectangle& r1, const Rectangle& r2);
#endif