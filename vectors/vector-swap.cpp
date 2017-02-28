#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
   Swaps the second and second-to-last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 2, 4, 1, 5, 9, 1, 6}.
   If the array has length < 2, do nothing.
   @param a a vector of integers      
*/
void swap2(vector<int>& a)
{
   vector <int> v;
   //reverse(a.begin()+1,a.end()-1);
   iter_swap(a.begin()+1,a.end()-2);

  for (int i = 0; i < a.size(); i++)
		{
	    	cout << a[i] << endl;
		}
}      


int main()
{
	vector <int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);
	a.push_back(1);
	a.push_back(5);
	a.push_back(9);
	a.push_back(2);
	a.push_back(6);
	//int alen = sizeof(a);
	if(a.size()<2)
	{

		for (int i = 0; i < a.size(); i++)
		{
	    	cout << a[i] << endl;
		}
	}
	else swap2(a);
}