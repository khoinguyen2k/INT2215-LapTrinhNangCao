#include <iostream>

using namespace std;

bool isPrime(int n)
{
   if (n <=1) return false;
   int a[25] ={2,3,5,7,11,13,17,19,23,29,31,
   37,41,43,47,53,59,61,67,71,73,79,83,89,97};
   for (int i =0; i <25; i++) {
      if (n ==a[i]) {
         return true;
         break;
      }
      if (n %a[i] ==0) {
         return false;
         break;
      }
   }
   bool valid =true;
   for (int i =2; i*i <=n; i++)
      if (n%i ==0) valid =false;
   return valid;
}
int main ()
{
   return 0;
}
