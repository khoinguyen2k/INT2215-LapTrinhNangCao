#include <iostream>
using namespace std;

int* getPointerToArray(int n)
{
   int *a =new int[n];
   for (int i =0; i <n; i++)
      cin >>a[i];
   return a;
}
int main()
{
   return 0;
}
