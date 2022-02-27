#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
   int n;
   cin >>n;
   vector<int> a(n);
   for (int i =0; i <n; i++)
      cin >>a[i];

   sort(a.begin(), a.end());
   vector<int>::iterator it;
   it = unique (a.begin(), a.end());
   n =it -a.begin();
   for (int i =0; i <n; i++)
      cout <<a[i] <<' ';

   return 0;
}
