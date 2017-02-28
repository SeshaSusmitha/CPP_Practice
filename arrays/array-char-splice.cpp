#include <iostream>
#include <cstring>

using namespace std;

/**
   Given a '\0'-terminated character array, split it by replacing 
   each space in the character array with a '\0'. Return the number
   of strings into which you have split the input.
*/
int split(char* words)
{
	
	char ch=' ';
	int count=0;
	int i=0, n=strlen(words);
   	for(i=0; i<n; i++)
   	{
   		if(words[i]==ch)
   		{
   			count++;
   			words[i]='\0';
   		}
   	}
   	return count+1;
}


int main()
{
	char words[] = "Hello  Goodbye Bonjour Arrivederci";
    int n = split(words);
    cout<<n<<endl;
}