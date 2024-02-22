#include "Game.h"
#include "Pixel.h"
#include <vector>
#include <cmath>
using namespace std;

Pixel::Pixel(Game* _game, int _row, int _col):
   game(_game),
   row(_row),
   col(_col),
   color(rand() %8)
{}
bool Pixel::isInsideBoard()
{
   return (0 <=row && row <=19 && 0 <=col && col <=9);
}
bool Pixel::canFall()
{
   bool canFall =true;
   if (row >=19) canFall =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[row +1][col] !='0')
         canFall =false;
   }
   return canFall;
}
void Pixel::fall() {row++;}
bool Pixel::canMoveLeft()
{
   bool canMoveLeft =true;
   if (col <=0) canMoveLeft =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[row][col -1] !='0')
         canMoveLeft =false;
   }
   return canMoveLeft;
}
void Pixel::moveLeft()
{
   if (canMoveLeft()) col--;
}
bool Pixel::canMoveRight()
{
   bool canMoveRight =true;
   if (col >=9) canMoveRight =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[row][col +1] !='0')
         canMoveRight =false;
   }
   return canMoveRight;
}
void Pixel::moveRight()
{
   if (canMoveRight()) col++;
}
