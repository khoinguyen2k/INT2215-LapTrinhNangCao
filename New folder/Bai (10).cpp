#include <iostream>
#include <string>
using namespace std;

struct Book{
	int access_no;
	string author;
	string title;
	///flag ==true mean there is issue
	bool flag;
	Book(int no, string aut, string tit, bool issue){
      access_no =no;
      author =aut;
      title =tit;
      flag =issue;
	}
};

int get_choice();
void print_starter_menu();
int main()
{
   int choice;
   print_starter_menu();
   choice =get_choice();
   switch (choice)
   {
      case 1:

      break;
      case 2:

      break;
      case 3:

      break;
      case 4:

      break;
      case 5:

      break;
      case 6:

      break;

      default:
      break;
   }
   return 0;
}

int get_choice()
{
   int c;
   cin >>c;
   return c;
}
void print_starter_menu(){
   cout <<"1 - Display book information\n"
"2 - Add a new book\n"
"3 - Display all the books in the library of a particular author\n"
"4 - Display the number of books of a particular title\n"
"5 - Display the total number of books in the library\n"
"6 - Issue a book\n";
}
