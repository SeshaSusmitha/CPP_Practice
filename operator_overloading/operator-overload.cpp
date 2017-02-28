/*
   Implement the - operator as a member function!
*/

#include "time.h"
#include <iostream>
using namespace std;



Time::Time(int hours, int minutes)
{
   minutesSinceMidnight = hours * 60 + minutes;
}

int Time::getHours()
{
   return minutesSinceMidnight / 60;
}

int Time::getMinutes()
{
   return minutesSinceMidnight % 60;
}

 int Time:: operator-(Time other)
{
	return minutesSinceMidnight - other.minutesSinceMidnight;
}



int main()
{
   Time t1(9, 15);
   Time t2(10, 0);
   cout << t2 - t1 << endl;
   cout << "Expected: 45" << endl;
   cout << t1 - t2 << endl;
   cout << "Expected: -45" << endl;
   Time t3(23, 59);
   cout << t3 - t1 << endl;
   cout << "Expected: 884" << endl;
   cout << t1 - t3 << endl;
   cout << "Expected: -884" << endl;
      
   return 0;
}
