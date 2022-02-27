#include <iostream>

using namespace std;

int main ()
{
   int n;
   cin >>n;
   int *a =new int[n];
   for (int i =0; i <n; i++)
      cin >>a[i];
   bool symmetry =true;
   for (int i =0; i <n; i++)
      if (a[i] !=a[n -1 -i])
      symmetry =false;
   cout <<(symmetry? "Symmetric array.": "Asymmetric array.");
   return 0;
}
