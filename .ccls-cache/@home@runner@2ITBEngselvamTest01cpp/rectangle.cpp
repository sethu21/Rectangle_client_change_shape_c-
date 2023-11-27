#include <iostream>
#include "rectangle.hpp"
#include "point.hpp"
#include <cmath>

using namespace std;

Rectangle::Rectangle():  b_left(0,0), u_right(0,0) {}
Rectangle::Rectangle(int bx, int by, int ux, int uy): b_left(bx, by), u_right(ux, uy){
  if(bx > ux || by > uy){
    b_left.set_x(min(bx,ux));
    b_left.set_y(min(by,uy));
    u_right.set_x(max(bx,ux));
    u_right.set_y(max(by,uy));
  }
}

Rectangle::Rectangle(const Point& bl, const Point& ur): b_left(bl), u_right(ur){
  int bx = bl.get_x();
  int by = bl.get_y();
  int ux = ur.get_x();
  int uy = ur.get_y();
  if(bx > ux || by > uy){
    b_left.set_x(min(bx,ux));
    b_left.set_y(min(by,uy));
    u_right.set_x(max(bx,ux));
    u_right.set_y(max(by,uy));
  }
}

 const Point& Rectangle::bottom_left() const{
   return b_left;
 }

const Point& Rectangle::upper_right() const{
  return u_right;
}
 void Rectangle::set_bottom_left(const Point& bl){
   b_left = bl;
 }

void Rectangle::set_upper_right(const Point& ur){
    u_right = ur;
}

int Rectangle::width() const{
  return u_right.get_x() - b_left.get_x();
}

 int Rectangle::height() const{
   return u_right.get_y() - b_left.get_y();
 }

double Rectangle::diagonal() const{
  int dx = width();
  int dy = height();
  return sqrt(dx*dx + dy*dy);
}

int Rectangle::area() const{
  return width() * height();
}

void Rectangle::move_rectangle(int dx, int dy){
  b_left.set_x(b_left.get_x() + dx);
  b_left.set_y(b_left.get_y() + dy);
  u_right.set_x(u_right.get_x() + dx);
  u_right.set_y(u_right.get_y() + dy);
  
}

void Rectangle::stretch(int dx, int dy){
  int new_width = width() + dx;
  int new_height = height() +dy;

  if(new_width >= 0 && new_height >= 0){
    u_right.set_x(b_left.get_x() + new_width);
    u_right.set_y(b_left.get_y() + new_height);
  }
}

void Rectangle::stretch(int dxy){
  stretch(dxy, dxy);
}

ostream& operator<<(ostream& os, const Rectangle& r){
  os << "[(" << r.bottom_left() << "," << r.upper_right() << ">";
  return os;
}

istream& operator<<(istream& is,  Rectangle& r){
  Point bl, ur;
  is >> bl >> ur;
  r.set_bottom_left(bl);
  r.set_upper_right(ur);
  return is;
}

bool equalAreas(const Rectangle& r1, const Rectangle& r2){
  return r1.area() == r2.area();
}