#include <iostream>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long
using namespace std;

int main ()
{
   int total, totalLegs;
   cin >> total >> totalLegs;
   bool flag = false;
   for (int numChicken =0; numChicken <totalLegs; numChicken++)
      if ( numChicken*2+(total-numChicken)*4 == totalLegs )
   {
      flag =true;
      cout <<"chicken = "<<numChicken <<", dog = " <<total -numChicken;
      break;
   }
   if (!flag) cout <<"invalid";
   return 0;
}
