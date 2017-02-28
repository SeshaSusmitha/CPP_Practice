#include <string>
#include <iostream>

using namespace std;

#include "employee.h"

int hashCode(const double& d)
{
   const int* p = reinterpret_cast<const int*>(&d);
   return p[0] ^ p[1];
}

/**
   Implement a hash function for hashing values of class
   Employee. Return the sum of the hashes of the name and 
   salary. 

   To hash a double, XOR the top and bottom 4-byte parts. Use
   the supplied function. 

   For example, the hash code of 2.0 is (0x40000000 ^ 0x00000000)
   or decimal 1073741824 
   (see https://en.wikipedia.org/wiki/Double-precision_floating-point_format)
*/
int hashCode(const Employee& e)
{
    string name = e.name();
    int sum = name[0];
    int name_length = name.length();
    for(int i = 0; i < name_length -1; i++)
    {
      sum = (sum * 31) + name[i+1];
    }
    double sal = e.salary();
    int hash_val = sum + sal;
    cout<<"hash_val = "<<hash_val<<endl;
    return hash_val;
    
}


int main()
{
   Employee e("susmita",10000);
   //Employee e("Fred Fielding", 95000);

   hashCode(e);
}