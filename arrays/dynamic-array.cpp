#include <iostream>
using namespace std;

int main()
{
	int x=3;
	int i;
	int** array = new int*[x];

  for(int i=0;i<x;i++)
    array[i] = new int[2];

  for(i=0;i<x;i++)
    for(int j = 0; j<2; j++)
      array[i][j] = 4;

  for(int i = 0; i < x; ++i)
    for(int j = 0; j < 2; ++j)
      cout << array[i][j] << "\n";


  return 0;

 }