#include <iostream>
#include "Seq.h"
using namespace std;

/*
  A Seq is a sequence of Box objects. The constructor Seq(int length)
  constructs a sequence of Box objects of the given length, all 
  constructed with the default constructor. Implement that constructor
  and the "big 3" memory management functions.
*/
  
Seq::Seq(int length)
{
  //cout << "\n\nSeq constructor" << endl;
   len = length;
   boxes = new Box[length];

}

Seq::Seq(const Seq& other)
{
  //cout << "Copy constructor" << endl;
  len = other.len;

   for(int j=0; j < other.len; j++)
   {
    boxes = new Box(*other.boxes);
   }

}

Seq& Seq::operator=(const Seq& other)
{
  //cout << "Operator overload" << endl;
 // cout<<other.len<<endl;
  
   for(int i=0; i<other.len; i++)
   {
    boxes[i] = other.boxes[i].value();
    // boxes = new Box(*other.boxes);
   }

   for(int i=other.len ; i < this->len ; i++)
   {
    boxes[i].~Box();
    //cout<<"i = " << i << endl;
   }
   len = other.len;
   return *this;	
}

Seq::~Seq()
{
  //cout << "\nSeq Destructor - " << this->len << endl;
  for(int i=0;i<this->len;i++)
    boxes->~Box();
}
