#include <iostream>
#include <string>

using namespace std;

bool valid_size(string s)
{
   return (6 <=s.size() && s.size() <=15);
}
bool start_by_num(string s)
{
   return ('0' <=s[0] && s[0] <='9');
}
bool only_num_and_char(string s)
{
   bool ans =true;
   for (int i =0; i <s.size(); i++)
   {
      if ( !( ('0' <=s[i] && s[i] <='9')
          || ('a' <=s[i] && s[i] <='z')
          || ('A' <=s[i] && s[i] <='Z') ) )
         ans =false;
   }
   return ans;
}
int main ()
{
   string s;
   cin >>s;
   if (valid_size(s) && only_num_and_char(s) && !start_by_num(s))
      cout <<"Valid username.";
   else cout <<"Invalid username.";
   return 0;
}
