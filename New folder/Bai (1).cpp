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

	Student sv;
	cin >>sv.roll_no;
	cin.ignore();
	getline(cin, sv.name);
	cin >>sv.age >>sv.mark;

	cin >>sv.roll_no;
	cin.ignore();
	getline(cin, sv.name);
	cin >>sv.age >>sv.mark;

	cout <<sv.roll_no <<endl;
	cout <<sv.name << endl;
	cout <<sv.age << endl;
	cout <<sv.mark;
	return 0;

}
