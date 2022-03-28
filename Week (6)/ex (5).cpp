#include <iostream>
using namespace std;

class Area{
   int length, breadth;
public:
   Area(int l, int b){
      length =l;
      breadth =b;
   }
   int returnArea(){
      return length *breadth /2;
   }
};
int main()
{
   int a, b;
   cin >>a >>b;
   Area triangle(a ,b);
   cout <<triangle.returnArea();
   return 0;
}
