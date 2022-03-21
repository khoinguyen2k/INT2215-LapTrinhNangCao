#include <iostream>
#include <string>
using namespace std;

struct Student{
	int roll_no;
	string name;
	int age;
	double mark;
	string address;
};

int main()
{
	Student sv[20];
	for (int i =1; i <=15; i++)
   {
      cin >>sv[i].roll_no;
      cin.ignore();
      getline(cin, sv[i].name);
      cin >>sv[i].age;
      cin.ignore();
      getline(cin, sv[i].address);
      cin >>sv[i].mark;
   }
	return 0;

}
