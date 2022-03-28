#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >>n;
   vector<int> a(n);
   for (int i =0; i <n; i++)
      cin >>a[i];

   sort(a.begin(), a.end() );
   if (a[0] !=a[1]) cout <<a[0] <<' ';
   for (int i =1; i <n -1; i++)
      if (a[i] != a[i +1])
      if (a[i] != a[i -1])
         cout <<a[i] <<' ';
   if (a[n -1] !=a[n -2]) cout <<a[n -1];
   return 0;
}
