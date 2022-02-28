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
   double *b =new double[n];
   for (int i =0; i <n; i++)
      cin >>a[i];
   for (int i =0; i <n; i++)
      cin >>b[i];
   double ans =0;
   for (int i =0; i <n; i++)
      ans +=a[i] *b[i];
   cout <<setprecision(2) <<fixed <<ans;
}
