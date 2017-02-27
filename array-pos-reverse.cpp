
/**
   Given pointers start and end that point to the 
   first and past the last element of a segment inside
   an array, return a new array holding the reverse
   of the segment. 
*/
#include <iostream>
using namespace std;
   int arr[]={5, 1, 4, 9, -4, 8, -9, 0};
int* reversing(int* start, int* end)
{

	int* arr_rev = new int[100];
	int j = 0;
	//cout<<"end = "<<*end;
	while (start <= end) 
 	{   
 		arr_rev[j++] =  *(end-1);
    end--;
    }
    return  arr_rev;
}


int main()
{

	int len= sizeof(arr) / sizeof(arr[0]);
	int *start = &arr[0];
	int *end = &arr[len-1];
	//cout<<"susmita"<<endl;
	int *arr_rev = reversing(arr+1,arr+5);
	int n=(sizeof(arr_rev) / sizeof(arr_rev[0]));
	for(int i=0;i<4;i++)
    	cout<<arr_rev[i]<<" ";
  cout<<"\n";
	
}