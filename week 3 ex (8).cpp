#include <iostream>
#include <string>

using namespace std;

int main ()
{
   string s;
   getline(cin, s);
   for (int i =0; i <=s.size() -4; i++)
   {
      if (s.substr(i, 4) =="Zues")
         s.replace(i, 4, "Zeus");
   }
   cout <<s;
   return 0;
}
