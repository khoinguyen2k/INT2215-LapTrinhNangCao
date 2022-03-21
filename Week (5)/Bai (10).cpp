///the exercise didn't give enough information for me to realise an exact answer
///screw it
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book{
	int access_no;
	string author;
	string title;
	///flag ==true mean there is issue
	bool flag;
	Book(int no =0, string aut ="", string tit ="", bool issue =false){
      access_no =no;
      author =aut;
      title =tit;
      flag =issue;
	}
};
void read_data();
int get_choice();
void print_starter_menu();
void function_1();
void function_2();
void function_3();
void function_4();
void function_5();
void function_6();

///global
ifstream file_in("book.txt");
ofstream file_out("book.txt", ios::app);
int choice;
Book b[100];
int book_num =0;
//////

int main()
{
   read_data();
   ///...///
   print_starter_menu();
   switch (choice)
   {
      case 1:
         function_1();
      break;
      case 2:
         function_2();
      break;
      case 3:
         function_3();
      break;
      case 4:
         function_4();
      break;
      case 5:
         function_5();
      break;
      case 6:
         function_6();
      break;

      default:
      break;
   }
   return 0;
}


void read_data()
{
   cout <<"loading..";
   int count =0;
   while (!file_in.eof() )
   {
      file_in >>b[count].access_no >> b[count].author
      >>b[count].title >>b[count].flag;
      count++;
   }
   book_num =count -1;
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
"6 - Issue a book\n"
"Input your choice(1..6): ";
   choice =get_choice();
}
void function_1()
{
   for (int i =0; i <book_num; i++)
   {
      cout <<b[i].access_no <<' ' <<b[i].author <<' '
      <<b[i].title <<' ' <<b[i].flag <<endl;
   }
}
void function_2()
{
   Book book;
   cin >>book.access_no >>book.author >>book.title >>book.flag;
   file_out <<book.access_no <<" " <<book.author <<" "
   <<book.title <<" " <<book.flag <<endl;
   b[book_num] =book;
   book_num++;
}
void function_3()
{
   string aut;
   cin >>aut;
   for (int i =0; i <book_num; i++)
   if (b[i].author ==aut)
   cout <<b[i].access_no <<endl;
}
void function_4()
{
   int res =0;
   string tit;
   cin >>tit;
   for (int i =0; i <book_num; i++)
   if (b[i].title ==tit) res++;
   cout <<"Number of book found: " <<res <<endl;
}
void function_5()
{
   cout <<"Total number of book: "<<book_num <<endl;
}
void function_6()
{
   ///issue base on accession number
   int acc_no;
   cin >>acc_no;
   for (int i =0; i <book_num; i++)
      if (b[i].access_no ==acc_no)
   {
      b[i].flag =true;
      break;
   }

}
