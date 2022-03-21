#include <iostream>

using namespace std;

struct Distance{
	int feet_no;
	int inch_no;
};

int main()
{
   Distance d1 ,d2;
   cout <<"nhap feet truoc inch sau" <<endl;
   cin >>d1.feet_no;
   cin >>d1.inch_no;
   cin >>d2.feet_no;
   cin >>d2.inch_no;
   if (d1.inch_no +d2.inch_no <12)
      cout <<d1.feet_no +d2.feet_no <<" feet " <<d1.inch_no +d2.inch_no <<" inch ";
   else cout <<d1.feet_no +d2.feet_no +1 <<" feet " <<d1.inch_no +d2.inch_no -12 <<" inch ";
	return 0;

}
