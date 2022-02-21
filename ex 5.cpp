#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
   double c, f;
   cin >>c;
   f = c *(double)(9) /5 + 32;
   cout << setprecision(2) << fixed <<f;
   return 0;
}
