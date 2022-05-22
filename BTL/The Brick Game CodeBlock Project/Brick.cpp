#include "Brick.h"
#include "Game.h"
#include <cmath>

vector<Pixel> Brick::createPixels(vector<string> data)
{
   vector<Pixel> pixels(4, Pixel(game));
   int count =0;
   size_t numRow =data.size();
   size_t numCol =data[0].size();
   for (size_t r =0; r <numRow; r++)
   for (size_t c =0; c <numCol; c++)
      if (data[r][c] !='0')
      {
         Pixel newPixel(game, row +r, col +c);
         pixels[count] =newPixel;
         pixels[count].setColor(color); count++;
      }
   return pixels;
}
Brick::Brick(Game* _game, int _row, int _col):
   game(_game),
   row(_row),
   col(_col),
   type(rand() %7),
   color(rand() %8),
   data(pixelIdData[type])
{
   pixels =createPixels(data);
   for (int i =0; i <4; i++)
      pixels[i].setColor(color);
}

bool Brick::canFall()
{
   bool ans =true;
   for (int i =0; i <4; i++)
      if (!pixels[i].canFall()) ans =false;
   return ans;
}
void Brick::fall()
{
   for (int i =0; i <4; i++)
      pixels[i].fall();
   row++;
}
void Brick::moveDown()
{
   if (canFall())
      fall();
}
void Brick::moveToBottom()
{
   while (canFall())
      fall();
}
bool Brick::canMoveLeft()
{
   bool ans =true;
   for (int i =0; i <4; i++)
      if (!pixels[i].canMoveLeft()) ans =false;
   return ans;
}
void Brick::moveLeft()
{
   if (canMoveLeft())
   {
      for (int i =0; i <4; i++)
         pixels[i].moveLeft();
      col--;
   }
}
bool Brick::canMoveRight()
{
   bool ans =true;
   for (int i =0; i <4; i++)
      if (!pixels[i].canMoveRight()) ans =false;
   return ans;
}
void Brick::moveRight()
{
   if (canMoveRight())
   {
      for (int i =0; i <4; i++)
         pixels[i].moveRight();
      col++;
   }
}
vector<string> rotate90deg(vector<string> data)
{
   size_t numRow =data.size();
   size_t numCol =data[0].size();
   vector<string> res(numCol, string(numRow, '0'));
   for (size_t r =0; r <numRow; r++)
   {
      for (size_t c =0; c <numCol; c++)
         res[c][numRow -r -1] =data[r][c];
   }
   return res;
}
bool Brick::isPixelsValid(vector<Pixel> pixels)
{
   bool res =true;
   vector<vector<char>> board =game->getBoard();
   for (size_t i =0; i <pixels.size(); i++)
   {
      if (!pixels[i].isInsideBoard())
         res =false;
      else
         if (board[pixels[i].getRow()][pixels[i].getCol()] !='0')
            res =false;
   }
   return res;
}
void Brick::spin()
{
   vector<string> newData =rotate90deg(data);
   vector<Pixel> newPixels =createPixels(newData);
   if (isPixelsValid(newPixels))
   {
      pixels =newPixels;
      data =newData;
   }
}
