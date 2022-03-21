#include <iostream>
using namespace std;

struct Date{
	int day;
	int month;
	int year;
	Date(int d, int m, int y){
      day =d;
      month =m;
      year =y;
   }
};

bool is_lunar(int y)
{
   if (y %4 ==0)
   {
      if (y %100 ==0 && y %400 !=0)
         return false;
      else return true;
   }
   else return false;
}

int main()
{
   int d, m, y;
   cin >>d >>m >>y;
   Date date(d, m ,y);
   date.day +=45;

   int day_of_month[13] ={0, 31,28,31,30,31,30,31,31,30,31,30,31};
   if (is_lunar(date.year)) day_of_month[2] =29;

   int next_month =(date.month +1) %12;
   int next_2_month =(date.month +2) %12;

   if (date.day >day_of_month[next_month])
   {
      date.day -=day_of_month[next_month];
      date.month++;
   }
   if (date.day >day_of_month[next_2_month])
   {
      date.day -=day_of_month[next_2_month];
      date.month++;
   }

   if (date.month >12)
   {
      date.month -=12;
      date.year++;
   }

   cout <<date.day <<" " <<date.month <<" " <<date.year;
	return 0;

}
