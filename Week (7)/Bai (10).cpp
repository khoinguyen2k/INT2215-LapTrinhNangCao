#include <iostream>
#include <cstring>
using namespace std;

bool is_char(char c)
{
   return ( ('a' <=c &&c <='z') ||('A' <=c &&c <='Z') );
}
void rFilter(char *s)
{
   int pos =strlen(s) -1;
   while (!is_char(s[pos]) )
   {
      s[pos] ='_';
      pos--;
   }
}
int main()
{
   char *s;
   s = new char[50];
   cin >> s;
   rFilter(s);
   cout << s;
   return 0;
}
