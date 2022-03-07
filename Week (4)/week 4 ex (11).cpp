#include <iostream>
#include <string>

#define ll long long
#define ull unsigned long long
using namespace std;

string pigLatin(string word)
{
   string ans;
   string sound ="ueoai";
   if (sound.find(word[0]) <sound.size())
      ans =word +"way";
   else
      ans =word.substr(1, word.size() -1) +word[0] +"ay";
   return ans;
}
int main ()
{
   string word ="all";
   cout <<pigLatin(word);
   return 0;
}
