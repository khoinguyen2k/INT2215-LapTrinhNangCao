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
   double *a =new double[n];
   double sum =0;
   for (int i =0; i <n; i++)
   {
      cin >>a[i];
      sum +=a[i];
   }
   double ave =sum /n;
   double ans =0;
   for (int i =0; i <n; i++)
      ans +=(a[i] -ave) *(a[i] -ave);
      ans /=n;
   cout <<setprecision(2) <<fixed <<ans;
}
