#include "point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
Point::Point(): x(0), y(0) {};
Point::Point(int x, int y) : x(x), y(y) {}

int Point::get_x() const {
  return x;
}

int Point::get_y() const {
  return y;
}

void Point::set_x(int x) {
  this->x = x;
}

void Point::set_y(int y) {
  this->y = y;
}

void Point::move_point(int dx, int dy){
  x += dx;
  y += dy;
}

double Point::distance(const Point &p) const{
  int dx = x - p.x;
  int dy = y - p.y;
  return sqrt(dx*dx + dy*dy);
}

ostream& operator<<(ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& point) {
  is>>point.x >> point.y;
  return is;
}