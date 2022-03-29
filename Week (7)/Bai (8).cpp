#include <iostream>
using namespace std;

int** transpose(int** matrix, int nRows, int nCols)
{
   int **ans =new int*[nCols];
   for (int i =0; i <nCols; i++)
   {
      ans[i] =new int[nRows];
      for (int j =0; j <nRows; j++)
         ans[i][j] =matrix[j][i];
   }
   return ans;
}
int main()
{
   return 0;
}
