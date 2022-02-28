#include <iostream>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long
using namespace std;

int main ()
{
   int n;
   cin >>n;

   for (int i =1; i <= 2 *n +1; i++)
   {
      for (int j =1; j <= 2 *n +1; j++)
      {
         if (abs(i -n -1) +abs(j -n -1) <=n)
            cout <<"* ";
         else cout <<". ";
      }
      cout <<endl;
   }
   return 0;
}
