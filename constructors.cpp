#include <iostream>
#include "BankAccount2.h"
using namespace std;


BankAccount::BankAccount(double initialBalance)
{   
   if(initialBalance >= 1000)
   	balance = initialBalance + 10;
   else
   	balance = initialBalance;
   //cout<<"initialBalance: "<<initialBalance<<endl;
}

void BankAccount::deposit(double amount)
{  
   balance = balance + amount;
   //return balance;
}

void BankAccount::withdraw(double amount)
{   
   balance = balance - amount;
}

double BankAccount::getBalance()
{   
   return balance;
}

int main()
{   
   BankAccount account1(10000);
   account1.deposit(1000);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 11010" << endl;

   BankAccount account2(999);
   account2.deposit(100);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 1099" << endl;      

   BankAccount account3(1000);
   account3.deposit(100);
   cout << "Balance: " << account3.getBalance() << endl;
   cout << "Expected: 1110" << endl;      
}


