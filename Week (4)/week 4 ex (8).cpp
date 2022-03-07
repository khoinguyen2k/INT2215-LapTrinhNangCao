#include <iostream>

using namespace std;

void readArray(int a[], int n)
{
   for (int i =0; i <n; i++)
      cin >>a[i];
}
bool compareArray(int array1[], int array2[], int n)
{
   bool ans =true;
   for (int i =0; i <n; i++)
      if (array1[i] !=array2[i]) ans =false;
   return ans;
}
int main ()
{
   return 0;
}
