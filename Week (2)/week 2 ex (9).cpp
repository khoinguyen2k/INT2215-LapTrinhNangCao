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
   for (int i =0; i <n; i++)
      cin >>a[i];
   for (int i =n -1; i >=0; i--)
      cout <<setprecision(2) <<fixed <<a[i] <<' ';
}
