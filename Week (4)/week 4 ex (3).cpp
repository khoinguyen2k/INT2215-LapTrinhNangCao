#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void printArrow(int n, bool left)
{
   for (int i =1; i <=2 *n -1; i++)
   if (!left)
   {
      //space
      for (int j =1; j <=n -1 -abs(i -n); j++)
         cout <<"  ";
      //star
      for (int j =1; j <=abs(i -n) +1; j++)
         cout <<'*';
      cout <<endl;
   }
   else
   {
      //space
      for (int j =1; j <=abs(i -n); j++)
         cout <<' ';
      //star
      for (int j =1; j <=abs(i -n) +1; j++)
         cout <<'*';
      cout <<endl;
   }
}
int main()
{
   int n, left;
   cin >>n >>left;
   printArrow(n, left);
   return 0;
}
