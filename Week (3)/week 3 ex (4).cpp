#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   int n;
   cin >>n;
   double *a =new double[n +1];
   for (int i =0; i <n; i++)
      cin >>a[i];
   double k;
   cin >>k;
   //process
   int pos =0;
   for (int i =0; i <n; i++)
      if (a[i] >k)
   {
      pos =i;
      break;
   }
   for (int i =n -1; i >=pos; i--)
      a[i +1] =a[i];
   a[pos] =k;
   //print
   for (int i =0; i <=n; i++)
      cout <<setprecision(2) <<fixed <<a[i] <<' ';

   return 0;
}
