#include <iostream>
using namespace std;

int** inputMatrix(int nRows, int nCols)
{
   int **val =new int*[nRows];
   for (int i =0; i <nRows; i++)
   {
      val[i] =new int[nCols];
      for (int j =0; j <nCols; j++)
         cin >>val[i][j];
   }
   return val;
}
void printMatrix(int** matrix, int nRows, int nCols)
{
   for (int i =0; i <nRows; i++)
   {
      for (int j =0; j <nCols; j++)
         cout <<matrix[i][j] <<' ';
      cout <<'\n';
   }

}
int main()
{
   return 0;
}
