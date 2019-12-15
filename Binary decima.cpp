#include<iostream>
#include <string>
using namespace std;

void decimal(double num);
void whole(int num);
void twoCompl(int size);
string who = "";

int main()
{
   double start;
   cout << "Enter the number to get it's binary value: ";
   cin >> start;
   
   whole(start);
   cout << who << "."; 
   
   if(start > 1)
      start -= (int)start;
   
   decimal(start);
   cout << endl;
   
   return 0;

}

void whole(int num)
{
   if(num < 1)
      return;
      
   if(num % 2 == 1)
   {
      who.insert(0, "1");
      whole(num / 2);
   }
   else
   {
      who.insert(0, "0");
      whole(num / 2);
   }
   
}

void decimal(double num)
{
   if(num == 1.0000 || num == 0)
   {
      cout << "0";
      return;
   }
   num *= 2;
   
   if(num >= 1.000)
   {
      cout << "1";
      decimal((num - 1));
   }
   else
   {
      cout << "0";
      decimal(num);
   }
}

void twoCompl(int size, bool found = false)
{
   if(size == 0)
      return;
   
   if(who[size - 1] == '0')
   {
      if(found)
         who[size - 1] = '1';
      
      twoCompl(size - 1, found);
   }
   else
   {
      if(!found)
      {
         found = true;
         twoCompl(size - 1, found);
      }
      else
      {
         who[size - 1] = '0';
         twoCompl(size - 1, found);
      }
   }
}