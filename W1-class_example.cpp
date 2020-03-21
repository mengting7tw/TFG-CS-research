/*
classes example
From: http://www.cplusplus.com/doc/tutorial/classes/
Topic: area calculation
Date: 2020/02/26
*/

#include <iostream>
#include <cmath>
using namespace std;

//Define class Rectangle
class Rectangle 
{
  private: 
    double width, height;
  public:
    void set_values(double, double);
    double area(){return width*height;} 
};

//Define set_values Method
void Rectangle::set_values(double x, double y)
{
  width = x; 
  height = y;
};

//Define class triangle
class Triangle1
{
  private:
    double side1, side2, side3;
  public:
    void set_values(double, double, double);
    double area();
};

class Triangle2
{
  private:
    double base, height;
  public:
    void set_values(double, double);
    double area();
};

//Define set_values Method
void Triangle1::set_values(double x, double y, double z)
{
  side1 = x;
  side2 = y;
  side3 = z;
};

double Triangle1::area() //Heron's formula
{
  double s = (side1 + side2 + side3) / 2;
  return sqrt(s * (s-side1) * (s-side2) * (s-side3));
}

void Triangle2::set_values(double x, double y)
{
  base = x;
  height = y;
}

double Triangle2::area() 
{
  return base * height / 2;
}

//Main function
int main () 
{
  Rectangle rect;
  rect.set_values(3, 4);
  cout << "rect area: " << rect.area() << endl;

  Triangle1 tri1;
  tri1.set_values(3, 4, 5);
  cout << "tri1 area: " << tri1.area() << endl;

  Triangle2 tri2;
  tri2.set_values(3, 6);
  cout << "tri2 area: " << tri2.area() << endl;

  return 0;
}

