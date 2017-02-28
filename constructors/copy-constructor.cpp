
/*
In the constructor, copy constructor, assignment operator, destructor
print messages "Constructing ...", "Copying ...", "Assigning ... to ...", "Destroying ...", and do what else is necessary. 
 */

#include <iostream>
#include "Trace.h"

using namespace std;
                   
Trace::Trace(string s)
{
  cout<<"Constructing "<<s<<endl;
  str = s;

}

Trace::Trace(const Trace& other) : str(other.str)
{
 	cout<<"Copying "<<other.str<<endl;

}

Trace& Trace::operator=(const Trace& other) 
{
	//cout<<"other.str = "<<other.str<<endl;
	//cout<<"str ="<<str<<endl;;
	str = other.str;
	cout<<"str ="<<str<<endl;;
  cout<<"Assigning "<<other.str<<" to "<<this->str<<endl;;
}

Trace::~Trace() 
{ 
	cout<<"Destroying "<<str<<endl;

}



Trace fun(Trace t)
{
   Trace r = t;
   return r;
}

int main()
{
   Trace t("Fred");
   Trace u("Wilma");
   u = fun(t);
   return 0;
}
