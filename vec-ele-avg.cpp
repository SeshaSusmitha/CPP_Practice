#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
	int input;
	double average, sum;
	//printf("Naren");

	vector <int> elements;
	cout<<"Enter Input array:  \n";
	while(cin>>input)
	{

		if(input == 0)
		{
			//cout<<"Exiting input loop \n";
			break;
		}
		else if(input>0)
		{

			elements.push_back(input);
		}
		else
		{
			continue;
		}
		
	}
	//cout<<"Input array is \n";
	for(int i = 0; i<elements.size(); i++)
	{
 		//cout << elements[i] <<", ";
 		if(elements[i]>0)
 			sum=sum+elements[i];
 		else continue;
 	}
 	cout<<"\n";
 	if(elements.size() == 0)
 	{
 		cout<<"No elements"<<endl;
 		exit(0) ;
 	}
 	else
 	{	
	 	average = sum/elements.size();
	 	cout<<"average: ";
	 	// cout.setf(ios::fixed);
	 	// cout.setf(average);
	 	// cout.precision(2);
	 	cout<<setprecision(2)<<fixed<<average<<endl;
	 }
}