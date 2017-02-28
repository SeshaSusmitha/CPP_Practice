#include <cstring>
#include <iostream>

using namespace std;

/**
   Given a '\0'-terminated character array, split it by replacing 
   each space in the character array with a '\0' and return a 
   newly allocated array of char* pointers to the resulting strings.
*/
char** split(char* words)
{
   // count spaces
   
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

   // store results
   char** result = new char*[count];
   int j=1;

   result[0]=words;

   for(i=0;i<n;i++)
   {
   	 if(words[i]=='\0')
   	 	result[j++]=words+(i+1);

   }

   for(j=0;j<count;j++)
   	cout<<result[j]<<endl;

   return result;
}


int main()
{
	char words[] = "Hello  Goodbye Bonjour Arrivederci";
	split(words);

}