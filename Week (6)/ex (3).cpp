#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >>n;
   int *a =new int[n];
   for (int i =0; i <n; i++)
      cin >>a[i];

   map<int, int> fre;
   for (int i =0; i <n; i++)
      fre[a[i]]++;
   sort(a, a +n);
   //output
   cout <<"Repeated number Frequency" <<endl;
   cout <<a[0] <<"\t\t" <<fre[a[0]] <<endl;
   for (int i =1; i <n; i++)
   if (fre[a[i]] >1)
   if (a[i] !=a[i -1])
      cout <<a[i] <<"\t\t" <<fre[a[i]] <<endl;
   return 0;
}
