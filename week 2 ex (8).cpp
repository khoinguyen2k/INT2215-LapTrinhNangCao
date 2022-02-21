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
      int ans =0;
   do
   {
      ans ++;
      n /=10;
   }
   while (n !=0);
      cout <<ans;
   return 0;
}
