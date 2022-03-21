#include <iostream>

using namespace std;

struct Complex{
	int real;
	int img;
	Complex (int _real =0, int _img =0){
      real =_real;
      img =_img;
	}
};

Complex add(Complex c1, Complex c2)
{
   Complex ans(0, 0);
   ans.real =c1.real +c2.real;
   ans.img =c1.img +c2.img;
   return ans;
}

Complex subtract(Complex c1, Complex c2)
{
   Complex ans(0, 0);
   ans.real =c1.real -c2.real;
   ans.img =c1.img -c2.img;
   return ans;
}
Complex multiply(Complex c1, Complex c2)
{
   Complex ans(0, 0);
   ans.real =c1.real *c2.real -c1.img *c2.img;
   ans.img =c1.real *c2.img +c1.img *c2.real;
   return ans;
}
int main()
{

	return 0;

}
