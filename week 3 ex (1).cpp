#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >>n;
   int *a =new int[n];
   int *b =new int[n];
   for (int i =0; i <n; i++)
      cin >>a[i];
   for (int i =0; i <n; i++)
      cin >>b[i];
   bool same =true;
   for (int i =0; i <n; i++)
      if (a[i] !=b[i]) same =false;
   cout <<(same? "YES" :"NO");

   return 0;
}
