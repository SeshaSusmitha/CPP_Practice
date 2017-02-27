#include "time2.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/*
  Implement the << operator!
*/

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

ostream& operator<<(ostream& out, Time t)
{
	//out<<t.hours<<t.minutes;
	if(t.getHours()<10)
	{
		out<<"0"<<t.getHours()<<":"<<t.getMinutes();	
	}
	else if(t.getMinutes()<10)
	{
		out<<t.getHours()<<":"<<t.getMinutes()<<"0";
	}
	else
	{
		out<<t.getHours()<<":"<<t.getMinutes();
	}
	//out<<t;
	//out<<setfill(0)<<setw(2)<<t.getHours();
	return out;
}



int main()
{
   Time t1(9, 15);
   Time t2(10, 0);
   Time t3(23, 59);
   cout << "t1: " << t1 << endl;
   cout << "Expected: 09:15" << endl;
   cout << "t2: " << t2 << endl;
   cout << "Expected: 10:00" << endl;
   cout << "t3: " << t3 << endl;
   cout << "Expected: 23:59" << endl;
   stringstream sout;
   sout << "t1: " << t1 << endl;
   cout << sout.str();
   cout << "Expected: 09:15" << endl;
      
   return 0;
}
