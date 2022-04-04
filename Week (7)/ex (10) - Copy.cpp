#include <iostream>
#include <iomanip>
using namespace std;

void print_a(double A)
{
   int val_1 =(int)A;
      string ans ="";
      do
      {
         int val =val_1 %16;
         if (val <10)
         {
            char ch ='0' +val;
            ans =ch +ans;
         }
         else
         {
            char ch;
            for (int i =10; i <=15; i++)
               if (val ==i)
                  ch ='A' +i -10;
            ans =ch +ans;
         }
         val_1 /=16;
      }
      while (val_1 !=0);

   cout <<"0x" +ans <<endl;
}
void print_b(double n)
{
   int val =(int)n;
   int digit =0;
   do
   {
      digit++;
      val /=10;
   }
   while (val !=0);
   int num_of_dot =15 -digit -3 -1;
   for (int i =0; i <num_of_dot; i++)
      cout <<"_";
   cout <<(n >=0? '+': '-');
   cout <<setprecision(2) <<fixed <<n;
}
void print_c(double C)
{
   double val =C;
   int count =0;
   while (val >=10)
   {
      val /=10;
      count++;
   }
   cout <<setprecision(9) <<fixed <<val;
   cout <<"E+" <<count;
}
int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
   ///a
   print_a(A);
   ///b
   print_b(B);
	}
	return 0;

}
