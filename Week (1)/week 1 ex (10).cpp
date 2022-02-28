#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
   int a, b, c;
   cin >>a >>b >>c;
   double p =(double)(a +b +c) /2;
   if (p <=a ||p <=b ||p <=c)
      cout <<"invalid";
   else
   {
      double s =sqrt(p *(p -a) *(p -b) *(p -c));
      cout <<setprecision(2) <<fixed <<s;
   }
   return 0;
}
