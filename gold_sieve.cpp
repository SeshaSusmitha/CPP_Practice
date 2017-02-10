/************ Name :Sesha Susmitha Yellamraju SJSU ID: 010806991 ************************/

#include <iostream>
#include <cstring>
using namespace std;


void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    int j=0;
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)//Setting index as true for all prime numbers
        {
            for (int i=p*p; i<=n; i += p)//Setting all multiples to false
                prime[i] = false;
        }
    }

/* Generating all prime numbers */

    for (int p=1; p<=n; p++)
    {
        if(p % 10 ==1) cout << endl;
        if (prime[p])
        {
            if(p==1)
                cout<<".  ";
            else if(p<10)
                cout<< p <<"  ";
            else
            cout << p << " ";
        } 
        else
        cout<<"."<<"  ";
    }
cout<<endl;
int k=0;

/* Generating even number as sum of possible prime combinations*/

cout<<endl;
cout<<"Test of Goldbach's Conjecture:";
cout<<endl;
cout<<endl;


  for(int i=4;i<=100;i=i+1)
  {
    int found=0;
    if(i%2==0)//Checking if the number is even
    {    
        for(int b=2;b<i;++b)
    	{	
    		for(int c=2;c<i;++c)
    		{
    			if((prime[b]) && (prime[c]) && (b+c==i) && (b<=c))
    				if(found==0)
    				{
         				cout<<i<<":  "<<b<<"  "<<c;
         				found=1;
         			}
         			else
         			{
         				cout<<endl;
         				cout<<"     ";
         				cout<<b<<"  "<<c;
         				
         			}
         	
    		}
        }
		
	}
	cout<<endl;
	
}

cout<<endl;
       
}


int main()
{
    int n = 100;
    cout << "Primes:" << endl;
    SieveOfEratosthenes(n);
    return 0;
}