#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s;
   cin >>s;
   for (int i =0; i <s.size(); i++)
   if (s[i] ==s[i +1])
      s.insert(i +1, "*");
   cout <<s;
   return 0;
}
