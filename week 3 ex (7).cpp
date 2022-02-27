#include <iostream>
#include <string>

using namespace std;

int main ()
{
   string s;
   getline(cin, s);
   int countAlpha =0, countNumber =0, countOther =0;
   for (int i =0; i <s.size(); i++)
   {
      char c =s[i];
      if ( ('a' <=c && c <='z') || ('A' <=c && c<= 'Z') )
         countAlpha++;
      else if ('0' <=c && c <='9')
         countNumber++;
      else countOther++;
   }
   cout <<countAlpha <<' ' <<countNumber <<' ' <<countOther;
   return 0;
}
