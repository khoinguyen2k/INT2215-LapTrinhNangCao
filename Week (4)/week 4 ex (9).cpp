#include <iostream>
#include <algorithm>

using namespace std;

bool comp(float a, float b)
{
   return (a >b);
}
void sort(float array[], int size, bool isAscending)
{
   if (isAscending)
      sort(array, array +size);
   else sort(array, array +size, comp);
}
int main ()
{
   return 0;
}
