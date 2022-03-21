#include <iostream>
#include <string>
using namespace std;

struct Employee{
   string name;
   int salary;
   int hour_per_day;
};

int main()
{
	Employee people[20];
	for (int i =1; i <=10; i++)
   {
      cin.ignore();
      getline(cin, people[i].name);
      cin >>people[i].salary >>people[i].hour_per_day;
   }
   ///increase salary
   for (int i =1; i <=10; i++)
      if (people[i].hour_per_day >=12)
         people[i].salary +=150;
      else if (people[i].hour_per_day >=10)
         people[i].salary +=100;
      else if (people[i].hour_per_day >=8)
         people[i].salary +=50;
   ///print
   for (int i =1; i <=10; i++)
      cout <<people[i].name <<" " <<people[i].salary <<endl;
	return 0;

}
