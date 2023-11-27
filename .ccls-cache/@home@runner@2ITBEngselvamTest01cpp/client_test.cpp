#include "point.hpp"
#include "rectangle.hpp"
#include <iostream>

using namespace std;

int main () {
 // int new_p1, new_p2;
  Point p1,p2;
  

  cout << "Point 1; "<< p2 << endl;
  cout << "Point 2; "<< p2 << endl;

  cout << "Enter the coordinates For the point p1: x y ==>  ";
  cin >> p1;

  cout << "Enter the coordinates For the point p2: x y ==> ";
  cin >> p2;

  cout << "Point 1: "<< p1 << endl;
  cout << "Point 2: "<< p2 << endl;

  cout << "the distance p1,p2 = " << p1.distance(p2) << endl;
  
  p1.move_point(2, 3);

  cout << "move Point p1 by (2,3): "<< p1 << endl;
  cout << "the distance p2,p1 = " << p2.distance(p1) << endl;


  cout << "---4 rectangles are created--" << endl;

  Rectangle r1;
  cout << " r1 is created using default constructor "<<endl;
  cout << " r1: "<< r1 << endl;

  Point p3(4,9);
  Point p4(10,5);

  Rectangle r2(p3,p4);
  cout << " r2 is created using the  constructor WITH Arguments(p3,p4) "<<endl;
  cout << " r2: "<< r2 << endl;

  Rectangle r3(1,2,3,4);
  cout << " r3 is created using the  constructor with argumnets(1,2,3,4)  "<<endl;
  cout << " r3: "<< r3 << endl;

  Rectangle r4(1,6,7,2);
  cout << " r4 is created using the  constructor with argumnets(1,6,7,2)  "<<endl;
  cout << " r4: "<< r4 << endl;

  cout<< "---Streaching, moving and shrinking rectangles---" << endl;
  r3.stretch(-8, 5);
  cout << " r3 after stretching by (-8,5): "<< r3 << endl;
  
  r3.stretch(3, 5);
  cout << " r3 after stretching by (6,-3): "<< r3 << endl;

  r3.move_rectangle(2, 3);
  cout << " r3 after moving by (2,3): "<< r3 << endl;

  cout << "---Calculating the side, area, diagonal of rectangle r3 " << endl;
  cout << " r3 height = " << r3.height()<< endl;
  cout << " r3 width = " << r3.width()<< endl;
  cout << " r3 area = " << r3.area()<< endl;
  cout << " r3 diagonal = " << r3.diagonal()<< endl;

  cout << "---comparing two rectangles" << endl;
  if(!equalAreas(r3,r4)){
    cout <<"The area of rectangle r3, r4 are diffrent.Changing the lenght of the sides of rectangle r3... "<< endl;
    int dx= r3.width() -r4.width();
    int dy= r3.height() -r4.height();
    r4.stretch(dx,dy);
    cout << " r4 after stretching by (dx,dy): "<< r4 << endl;
  }

  cout << "r3 = " << r3 << endl;
  cout << "r4 = " << r4 << endl;
  cout << "r3,r4 ==> "<< boolalpha<< equalAreas(r3,r4) << endl;
  return 0;
  
}