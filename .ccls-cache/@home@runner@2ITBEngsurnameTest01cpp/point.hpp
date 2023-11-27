#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point();                // default constructor
    Point(int x, int y);    // parameter constructor

    int get_x() const;
    int get_y() const;

    void set_x(int x);
    void set_y(int y);
    void move_point(int dx, int dy);
    double distance(const Point &p) const;
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is,  Point& point);

};

#endif