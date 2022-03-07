#include <iostream>
#include <string>

using namespace std;

string toLower(string s)
{
   string ans =s;
   for (int i =0; i <s.size(); i++)
      ans[i] =tolower(s[i]);
   return ans;
}
int main ()
{
   //Example
   string s;
   s ="Convert all the StrIng to LowerCase.";
   cout <<toLower(s);
   return 0;
}
