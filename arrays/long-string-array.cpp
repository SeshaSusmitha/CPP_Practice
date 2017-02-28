#include <cstring>
#include <iostream>

using namespace std;

/**
   Given an array of strings of length n > 0, return the longest
   string. If there are multiple strings of the same maximum length,
   return the first one.
*/
	char* longest(char** words, int n);
	char* longest(char** words, int n)
{
   
	int max_length=strlen(*words);
	int i=0;
	int str_len[4];
	int location = 0;
	
	while(i<n)
	{
		str_len[i]=strlen(*(words+i));
		i++;
	}
	int max_len= str_len[0];
	for(int i=0;i<n;i++)
	{
		if(str_len[i]>max_len)
		{
			max_len=str_len[i];
			location=i;
		}
	}
	return *(words+location);
}

int main()
{
	char words[] = "Hello\0Goodbye\0Bonjour\0Arrivederci";
	string largest_string;
	char* starts[] = { words, words + 6, words + 14, words + 22 };
	cout<<longest(starts,4)<<endl;

}