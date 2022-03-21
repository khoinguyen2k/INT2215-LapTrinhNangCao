#include <iostream>
#include <string>
using namespace std;

struct Student{
	int roll_no;
	string name;
	int age;
	double mark;
};

int main()
{
	Student sv[10];
	for (int i =1; i <=5; i++)
   {
      cin >>sv[i].roll_no;
      cin.ignore();
      getline(cin, sv[i].name);
      cin >>sv[i].age >>sv[i].mark;
   }

   cout <<sv[2].roll_no <<endl;
	cout <<sv[2].name << endl;
	cout <<sv[2].age << endl;
	cout <<sv[2].mark;
	return 0;

}
