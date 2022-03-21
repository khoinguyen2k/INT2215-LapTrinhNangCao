#include <iostream>

using namespace std;

struct Mark{
	int roll_no;
	string name;
	double chem_marks, math_marks, phy_marks;
};

int main(){

	Mark sv[10];
	for (int i =1; i <=5; i++)
   {
      cin >>sv[i].roll_no;
      cin.ignore();
      getline(cin, sv[i].name);
      cin >>sv[i].chem_marks >>sv[i].math_marks >>sv[i].phy_marks;
   }
   double max_chem =sv[1].chem_marks;
   double max_math =sv[1].math_marks;
   double max_phy =sv[1].phy_marks;

   for (int i =2; i <=5; i++)
   {
      if (sv[i].chem_marks >max_chem) max_chem =sv[i].chem_marks;
      if (sv[i].math_marks >max_math) max_math =sv[i].math_marks;
      if (sv[i].phy_marks >max_phy) max_phy =sv[i].phy_marks;
   }

   cout <<"Name Chem_percent Math_percent Phy_percent" <<endl;
   for (int i =1; i <=5; i++)
   {
      double chem_percent =(double)sv[i].chem_marks /max_chem *100;
      double math_percent =(double)sv[i].math_marks /max_math *100;
      double phy_percent =(double)sv[i].phy_marks /max_phy *100;
      cout <<sv[i].name <<" " <<chem_percent <<" " <<math_percent <<" " <<phy_percent;
      cout <<endl;
   }
	return 0;

}
