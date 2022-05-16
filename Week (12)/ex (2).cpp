#include <iostream>
#include <cmath>
using namespace std;
class Complex{
public:
   Complex(int x =0, int y =0)
   {
      real =x; img =y;
   }
   friend ostream &operator<<(ostream &os, const Complex &c)
   {
      os <<c.real <<' ';
      if (c.img !=0)
      {
         double val =abs(c.img);
         os <<(c.img >0? '+': '-');
         os <<' ' <<val <<'i';
      }
      return os;
   }
   friend istream &operator>>(istream &is, Complex &c)
   {
      is >>c.real >>c.img;
      return is;
   }
   Complex operator+(const Complex &c)
   {
      Complex ans;
      ans.real =this->real +c.real;
      ans.img =this->img +c.img;
      return ans;
   }
   Complex operator-()
   {
      Complex ans;
      ans.real =-this->real;
      ans.img =-this->img;
      return ans;
   }
private:
   double real, img;
};
int main()
{
   Complex c1,c2,c3;
   cout << "Enter two complex values: ";
   cin >> c1 >> c2;
   c3 = c1 +c2;
   cout << "The sum is: " << c3 << endl;
   cout << "and negating the sum yields: " << -c3 << endl;
   return 0;
}
