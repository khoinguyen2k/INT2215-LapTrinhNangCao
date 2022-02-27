#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

bool comp(double a, double b)
{
   return (a >b);
}
int main()
{
   int n;
   cin >>n;
   double *a =new double[n];
   for (int i =0; i <n; i++)
      cin >>a[i];

   sort(a, a +n, comp);
   for (int i =0; i <n; i++)
      cout <<setprecision(2) <<fixed <<a[i] <<' ';

   return 0;
}
