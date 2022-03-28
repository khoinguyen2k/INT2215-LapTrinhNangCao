#include <iostream>
using namespace std;

int main()
{
   int n, d;
   cin >>n >>d;
   int *a =new int[n];
   for (int i =0; i <n; i++)
      cin >>a[i];

   d =d %n;
   int *ans =new int[n];
   for (int i =0; i <n; i++)
   {
      int pos =(i +d) %n;
      ans[i] =a[pos];
      cout <<ans[i] <<' ';
   }
   return 0;
}
