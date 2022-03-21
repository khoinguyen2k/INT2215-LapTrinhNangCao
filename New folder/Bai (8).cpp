#include <iostream>
#include <string>
using namespace std;

struct Customer{
   string name;
   int acc_no;
   int balance;
};

void print_less_than_200(Customer *user, int n)
{
   for (int i =1; i <=n; i++)
   if (user[i].balance <200)
      cout <<user[i].name <<endl;
}
void add_100_and_print(Customer *user, int n)
{
   for (int i =1; i <=n; i++)
   if (user[i].balance >1000)
   {
      user[i].balance +=100;
      cout <<user[i].balance <<endl;
   }
}
int main()
{
   cout <<"num of customers: ";
   int n;
   cin >>n;
	Customer *user =new Customer[n +1];
	for (int i =1; i <=n; i++)
   {
      cin.ignore();
      getline(cin, user[i].name);
      cin >>user[i].acc_no >>user[i].balance;
   }
	return 0;

}
