#include <iostream>

using namespace std;
class Point {
public:
   Point( );
   Point(int xval, int yval);
   ///part b: fix function
   Point operator+(Point p);
   ///part d: add friend
   friend istream &operator>>(istream &is, Point &p);
   ///part f:
   friend ostream &operator<<(ostream &os, Point &p);
   ///
private:
   int xloc;
   int yloc;
};
Point::Point( )
{
   xloc =0;
   yloc =0;
}
Point::Point(int xval, int yval)
{
   xloc =xval;
   yloc =yval;
}

///part a
int sum(int a, int b)
{
   return (a +b);
}
///part b: remove friend and take function outside
///part c also
Point Point::operator+(Point p)
{
   Point ans;
   ans.xloc =sum(this->xloc, p.xloc);
   ans.yloc =sum(this->yloc, p.yloc);
   return ans;
}
///part d: output overload operator return type is: ostream.
///not related e.g
istream &operator>>(istream &is, Point &p)
{
   is >>p.xloc >>p.yloc;
   return is;
}
///part e

///part f
ostream &operator<<(ostream &os, Point &p)
{
   os <<p.xloc <<"," <<p.yloc;
   return os;
}
int main()
{
   Point p1, p2(2, 3);
   cin >>p1;
   p1 =p1 +p2;
   cout <<p1;
   return 0;
}
