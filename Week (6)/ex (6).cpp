#include <iostream>
#include <string>
using namespace std;

class Student{
   string name;
   int roll_no;
public:
   Student(string s, int n){
      name =s;
      roll_no =n;
   }
};
int main()
{
   Student sv("John", 2);
   return 0;
}
