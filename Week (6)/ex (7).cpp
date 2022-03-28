#include <iostream>
#include <string>
using namespace std;

class Employee{
public:
   string name;
   int year_of_joining;
   int salary;
   string address;
   Employee(string n ="", int y =0, int s =0, string ad =""){
      name =n;
      year_of_joining =y;
      salary =s;
      address =ad;
   }
   void setEmployee(string n ="", int y =0, int s =0, string ad =""){
      name =n;
      year_of_joining =y;
      salary =s;
      address =ad;
   }
};
int main()
{
   Employee e[3];
   e[0].setEmployee("Robert", 1994, 123, "64C- WallsStreat");
   e[1].setEmployee("Sam", 2000, 150, "68D- WallsStreat");
   e[2].setEmployee("John", 1999, 69, "26B- WallsStreat");

   cout <<"Name\tYear of joining\tAddress\n";
   for (int i =0; i <3; i++)
   {
      cout <<e[i].name <<'\t' <<e[i].year_of_joining <<"\t\t"
      <<e[i].address <<endl;
   }
   return 0;
}
