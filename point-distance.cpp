#include <cmath>
#include <iostream>

#include "point.h"
using namespace std;



double distance(Point a,Point b);
Point midpoint(Point a, Point b);
/**
   Compute the distance between two points.
   @param a, b two points
   @return the distance between them.
*/
double distance(Point a, Point b)
{
    double val1 = pow((b.x-a.x), 2);
    double val2 = val1 + pow((b.y-a.y), 2);
    double distance = sqrt(val2);
    cout<< "distance = ";//<<distance<<endl;
    return distance;
   
}

/**
   Compute the midpoint between two points.
   @param a, b two points
   @return the point halfway between them.
*/
Point midpoint(Point a, Point b)
{
    a.x = (a.x+b.x)/2;
    a.y = (a.y+b.y)/2;
    return a;
}

int main()
{
	Point a;
  a.x = 1;
  a.y = 2;

  Point b;
  b.x= 4;
  b.y=6;
  
  Point c;

	cout<<distance(a,b)<<endl;
	c = midpoint(a,b);
  cout<<c.x<<" ";
  cout<<c.y<<endl;;
}
