#include <iostream>

using namespace std;

double calculate (double num1, char operat, double num2)
{
   switch (operat)
   {
      case '+':
         return (num1 +num2);
      break;
      case '-':
         return (num1 -num2);
      break;
      case '*':
         return (num1 *num2);
      break;
      case '/':
         return (num1 /num2);
      break;

      default:
      break;
   }
}
int main ()
{
   return 0;
}
