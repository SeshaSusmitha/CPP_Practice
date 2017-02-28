#include "Box.h"
#include <iostream>
using namespace std;

Box::Box() : _value(0) { /*cout<<"\tDefault Box const "<<endl;*/ _objects++; }
Box::Box(int v) : _value(v) { /*cout<<"\tBox const "<<v<<endl;*/ _objects++; /*cout<<_objects<<endl;*/ }
Box::Box(const Box& other) : _value(other._value) {/*cout<<"\tCopy const"<< */_objects++; }
Box::~Box() { /*cout << " Box Destructor" << endl;*/ _value = 666; _objects--; }
Box& Box::operator=(const Box& other) {/*cout<<"\tBox operator overload "<<endl;*/ _value = other._value;  return *this; }
int Box::value() const { return _value; }
void Box::value(int v) { _value = v; }
int Box::objects() { return _objects; }

int Box::_objects;
