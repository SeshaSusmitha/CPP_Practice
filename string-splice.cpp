#include <string.h>
#include <iostream>
using namespace std;

/**
   Return a string that interleaves the characters in strings a and b.
   If one string is longer than the other, append the suffix.
   For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
*/
string splice(string a,string b);
string splice(string a, string b)
{
	string c;
	int i=0,j=0;
	while((a[i] || b[i]) != '\0')
	{
		
		c.push_back(a[i]);
		c.push_back(b[i]);
		i++;
		
	}
	return c;
   
   //cout<<c;
}

int main()
{
	string a,b,c;
	//a="Hello";
	//b="GoodBye";
	a="Hello";
	b="Universe";
	c=splice(a,b);
	cout<<c;
	cout<<endl;
	return 0;
}
