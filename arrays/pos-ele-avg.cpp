/**
   Computes the average of all positive elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all positive elements in a, or 0 if there are none.
*/

#include <iostream>
using namespace std;


double avgpos(int a[],int alen);

int main()
{
	int a[] = {1,2,3,-4,0,1,2,-8};
	//int a[]={-1,-2,-3,-4,-5};
	//int alen = sizeof(a);
	int alen= end(a)-begin(a);
	cout<<avgpos(a,alen)<<endl;

}


double avgpos(int a[], int alen)
{
	int count=0;
	double average=0,sum;
	//cout<<"alen is: "<<alen<<endl;;
	for(int i=0; i<alen;i++)
	{
		//cout<<a[i]<<endl;
		if(a[i]>0)
		{
			count++;
			sum=sum+a[i];
		}
		else
			continue;
	}
	// cout<<"sum is: "<<sum<<endl;
	// cout<<"count is: "<<count<<endl;
	if(count>0)
	{
		average = sum/count;
	}
	
	//cout<<"Hi"<<endl;;
	return average;
}

