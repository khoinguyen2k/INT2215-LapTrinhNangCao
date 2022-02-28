#include <iostream>
#include <string>

using namespace std;

int main ()
{
   string s;
   getline(cin, s);
   int num_word =1;
   for (int i =0; i <s.size(); i++)
      if (s[i] ==' ') num_word++;
   cout <<num_word;
   return 0;
}
