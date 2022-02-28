#include <iostream>
#include <string>

using namespace std;

int main ()
{
   string s;
   getline(cin, s);
   int countStartSpaces =0;
   while (s[countStartSpaces] ==' ')
      countStartSpaces++;
   string s1;
   s1 =s.substr(countStartSpaces, s.size() -countStartSpaces);
   while (s1.find("  ") <s1.size() )
   {
      int pos =s1.find("  ");
      s1.erase(pos ,1);
   }
   cout <<s.substr(0, countStartSpaces) <<s1;
   return 0;
}
