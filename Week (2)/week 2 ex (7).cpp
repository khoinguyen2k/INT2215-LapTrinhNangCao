#include <iostream>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long
using namespace std;

int main ()
{
   ll n;
   cin >>n;

   ll i =1;
   double sum =1, old_sum =0;
   double add =1;
   while (sum -old_sum >0.001)
   {
      old_sum =sum;
      add = add *n /i;
      sum +=add;
      i++;
   }
   cout <<setprecision(4) <<fixed <<sum;
   return 0;
}
