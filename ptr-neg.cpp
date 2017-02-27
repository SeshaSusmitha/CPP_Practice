//SOLUTION
/**
   Return a pointer to the first negative element in 
   the given array which has length n. If there is no negative element,
   return a pointer past the last element. 
*/
 #include <iostream>
 using namespace std;
int* firstneg(int* arr, int n)
{
	//cout<<arr[n-1]<<endl;
   for(int i=0;i<n;i++)
   {
   	if(arr[i]<0)
   	{
   		return &arr[i];
   	}
   	
   }
   return &arr[n];
}

int main()
{
	//int arr[]={1,3,5,7,9,2,4,6,8};
	int arr[]={1, 4, 9, 0};
	int n,*r;
	n=(sizeof(arr) / sizeof(arr[0])) ;
	r=firstneg(arr,n);
	cout<<r<<endl;
}
