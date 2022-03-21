#include <iostream>

using namespace std;

struct Student{
	int roll_no;
	string name;
	int age;
	string address;
};

void print_age_14(Student* sv, int n)
{
   for (int i =1; i <=n; i++)
   if (sv[i].age ==14)
      cout <<sv[i].name <<endl;
}
void print_even_roll(Student* sv, int n)
{
   for (int i =1; i <=n; i++)
   if (sv[i].roll_no %2 ==0)
      cout <<sv[i].name <<endl;
}
void print_detail(Student* sv, int n)
{
   for (int i =1; i <=n; i++)
   if (sv[i].roll_no >=0)
      cout <<sv[i].roll_no <<" " <<sv[i].name <<" " <<sv[i].age
      <<" " <<sv[i].address <<endl;
}
int main()
{
   cout <<"input num of student: ";
   int n;
	cin >>n;
	Student *sv =new Student[n +1];
	for (int i =1; i <=n; i++)
   {
      cin >>sv[i].roll_no;
      cin.ignore();
      getline(cin, sv[i].name);
      cin >>sv[i].age;
      cin.ignore();
      getline(cin, sv[i].address);
   }
	return 0;

}
