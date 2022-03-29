#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *s)
{
   char* ans =new char[strlen(s)];
   for (int i =0; i <strlen(s); i++)
      ans[i] =s[i];
   for (int i =0; i <strlen(s); i++)
      s[i] =ans[strlen(s) -i -1];

}
int main()
{
   char *s;
   s = new char[50];
   cin >> s;
   reverse(s);
   cout << s;
   return 0;
}
