#include <string>
#include <iostream>

using namespace std;

/**
   Given a string, return a string of all digits contained in it. 
   Use recursion. Do not use loops.
   A digit is a character between '0' and '9' inclusive.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
string digits(string str)
{
  static string str1 = "";
  if(str.size() == 0)
  {
  	return str1;
  }
  else
  {	

   if(isdigit(str.at(0)))
   {
   		str1.push_back(str.at(0));
   }
   if(str.length() > 1)
   {
   	digits(str.substr(1));
   }

   return str1;
  }

}

int main()
{
	//string str = "s1u9s9m0i";
	string str = "11-11-2016";
	cout<<digits(str)<<endl;
}
