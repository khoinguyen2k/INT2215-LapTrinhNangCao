#include <iostream>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long
using namespace std;

int main ()
{
   int n;
   cin >>n;
   for (int i = 1; i <= 2*n + 1; i++) {
    for (int j = 1; j <= 2*n + 1; j++){
        if ( i + j == (2*n+1)+1 || i ==j ) { //
            cout<<"* ";
        }else{
            cout<<". ";
        }
    }
    cout<<endl;
}
   return 0;
}
