#include "Game.h"
#include "Pixel.h"
#include <vector>
using namespace std;

Pixel::Pixel(Game* _game, int x, int y):
   game(_game),
   id_x(x),
   id_y(y)
{}
bool Pixel::canFall()
{
   bool canFall =true;
   if (id_y >=19) canFall =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[id_x][id_y +1] !='0')
         canFall =false;
   }
   return canFall;
}
void Pixel::fall() {id_y++;}
bool Pixel::canMoveLeft()
{
   bool canMoveLeft =true;
   if (id_x <=0) canMoveLeft =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[id_x -1][id_y] !='0')
         canMoveLeft =false;
   }
   return canMoveLeft;
}
void Pixel::moveLeft()
{
   if (canMoveLeft()) id_x--;
}
bool Pixel::canMoveRight()
{
   bool canMoveRight =true;
   if (id_x >=9) canMoveRight =false;
   else
   {
      vector<vector<char>> board =game->getBoard();
      if (board[id_x +1][id_y] !='0')
         canMoveRight =false;
   }
   return canMoveRight;
}
void Pixel::moveRight()
{
   if (canMoveRight()) id_x++;
}
