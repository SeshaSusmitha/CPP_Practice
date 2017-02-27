// #include <iostream>
// #include <iomanip>

// int main() {
//     double pi = 3.141592653589;
//     std::cout << std::fixed << std::setprecision(2) << pi << '\n';
//     return 0;
// }



#include <iostream>

using namespace std;

int main(){


double num;
double input;
double sum = 0;
double avg;

cout << "Please enter a set of numbers. Enter a non-number to quit: "
  << endl;
cin >> num;

while (cin >> num) // When value is not a number, quit.

for(int i = 1; i <= num; i++){

  cin >> input;
  sum += input;
}

avg = sum / num;
cout << "average = " << avg << endl;

return 0;

}