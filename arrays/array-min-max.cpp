/**
   Compute the minimum and maximum value in a non-empty array.
   @param arr the array
   @param n the length of the array
   @param min a pointer to a variable holding the minimum
   @param max a pointer to a variable holding the minimum
*/


 #include <iostream>
 using namespace std;
void minmax(int* arr, int n, int *min, int *max)
{
	*min=arr[0];
	*max=arr[0];
	for(int i=0;i<n;i++)
	{
		//cout<<arr[i]<<" ";
		if(arr[i]<*min)
			*min=arr[i];
		if(arr[i]>*max)
			*max=arr[i];
	} 
	cout<<*min<<endl;
	cout<<*max<<endl;

}


int main()
{
	int arr[]={1,3,5,7,9,2,4,6,8};
	int n,min,max;
	n=(sizeof(arr) / sizeof(arr[0])) ;
		//cout<<n<<endl;
	minmax(arr,n,&min,&max);

}
