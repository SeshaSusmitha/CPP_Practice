#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(const char *msg, vector<int> vect);

int main()
{
  vector<int> v;

  for(int i=0; i<10; i++) v.push_back(i);

  show("Original order: ", v);

  rotate(v.begin(), v.begin()+1, v.end());
  show("Order after rotating left one position: ", v);

  return 0;
}

void show(const char *msg, vector<int> vect) {
  cout << msg << endl;
  for(unsigned i=0; i < vect.size(); ++i)
    cout << vect[i] << endl;
}