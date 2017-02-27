
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

/*
  Override the & and + operators!
*/

#include "interval.h"

Interval::Interval()
{
   xmin = 0;
   xmax = 0;
}

Interval::Interval(int xmin, int xmax)
{
   this->xmin = xmin;
   this->xmax = xmax;
}

bool Interval::isEmpty() const
{
   return xmin >= xmax;
}
   
string Interval::toString() const
{
   stringstream sout;
   sout << "[" << xmin << ", " << xmax << ")";
   return sout.str();
}

Interval operator+(const Interval& a, const Interval& b)
{
   Interval c;
   // c.xmin = a.xmin + b.xmin;
   // c.xmax = a.xmax + b.xmax;
   // return c;

   if(a.isEmpty())
      return b;
   else if(b.isEmpty())
      return a;
   else
   {
      if(a.xmin < b.xmin)
         c.xmin = a.xmin;
      else
         c.xmin = b.xmin;
      if(a.xmax > b.xmax)
         c.xmax = a.xmax;
      else
         c.xmax = b.xmax;
      return c;
   }
}

Interval operator&(const Interval& a, const Interval& b)
{
   //cout<<"hi";
   Interval c;
   if((a.xmax > b.xmin) && (a.xmax < b.xmax))
   {
      c.xmin = a.xmax - b.xmin;
      c.xmax = a.xmax;
   }
   else if((b.xmin < a.xmax) && (b.xmax < a.xmax))
   {
      c.xmin = b.xmax - a.xmin;
      c.xmax = b.xmax;
   }

   else
   {
      c.xmin = 0;
      c.xmax = 0;
   }

   // c.xmin = b.xmin;
   // c.xmax = a.xmax;
   return c;
}




int main()
{
   Interval r(1, 4);
   Interval s(2, 5);
   Interval t = r & s;
   cout << t.toString() << endl;
   cout << "Expected: [2, 4)" << endl;

   r = Interval(1, 2);
   s = Interval(3, 4);
   t = r & s;
   cout << t.toString() << endl;
   cout << "Expected: [0, 0)" << endl;   

   t = r + s;
   cout << t.toString() << endl;
   cout << "Expected: [1, 4)" << endl;

   t = (r & s) + r;
   cout << t.toString() << endl;
   cout << "Expected: [1, 2)" << endl;

   t = s + (r & s);
   cout << t.toString() << endl;
   cout << "Expected: [3, 4)" << endl;

   return 0;
}

