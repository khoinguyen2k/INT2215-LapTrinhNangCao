#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const int a, const int b)
{
   return (a >b);
}
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2)
{
   int *ans =new int[lenArr1 +lenArr2];
   for (int i =0; i <lenArr1; i++)
      ans[i] =firstArr[i];
   for (int i =0; i <lenArr2; i++)
      ans[lenArr1 +i] =secondArr[i];

   bool is_inc =(firstArr[lenArr1 -1] >firstArr[0]);
   if (is_inc)
   {
      sort(ans, ans +lenArr1 +lenArr2);
   }
   else
      sort(ans, ans +lenArr1 +lenArr2, comp);

   return ans;
}
int main()
{

   return 0;
}
