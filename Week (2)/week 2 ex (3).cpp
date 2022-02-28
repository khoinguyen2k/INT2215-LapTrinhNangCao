#include <iostream>
#include <cmath>
#include <string>

#define ll long long
#define ull unsigned long long
using namespace std;

bool is_square(ull n)
{
   return (n ==(ull)sqrt(n) *(ull)sqrt(n));
}
int main ()
{
   ull L, R;
   cin >>L >>R;
   ull up_bound =(ull)sqrt(R);
   ull low_bound =(ull)sqrt(L);
   if (!is_square(L)) low_bound++;
   for (ull i =low_bound; i <=up_bound; i++)
      cout <<(ull)(i *i)<<' ';
   return 0;
}
