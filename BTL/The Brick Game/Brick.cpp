#include "Brick.h"
#include "Game.h"
#include <ctime>
#include <cmath>

vector<Pixel> Brick::createPixels(vector<string> data)
{
   vector<Pixel> pixels(4, Pixel(game));
   int count =0;
   ///PROBLEM HERE!!!
   for (size_t row =0; row <data[0].size(); row++)
   for (size_t col =0; col <data.size(); col++)
      if (data[col][row] !='0')
      {
         Pixel newPixel(game, id_x +row, id_y +col);
         pixels[count] =newPixel; count++;
      }
   return pixels;
}
Brick::Brick(Game* _game, int x, int y):
   game(_game),
   id_x(x),
   id_y(y),
   type(rand() %7),
   data(pixelIdData[type])
{
   pixels =createPixels(data);
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
   id_y++;
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
      id_x--;
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
      id_x++;
   }
}

vector<string> transpose(vector<string> data)
{
   vector<string> res;
   size_t row =data.size();
   size_t col =data[0].size();
   for (size_t i =0; i <col; i++)
   {
      string s ="";
      for (size_t j =0; j <row; j++)
      {
         s +=data[j][i];
      }
      res.push_back(s);
   }
   return res;
}
void Brick::spin()
{
   vector<string> newData =transpose(data);
   vector<Pixel> newPixels =createPixels(newData);
   pixels =newPixels;
   data =newData;
}
