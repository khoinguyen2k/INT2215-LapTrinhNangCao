#ifndef BRICK_H
#define BRICK_H

#include <string>
#include <vector>
#include "Pixel.h"
using namespace std;
const vector<vector<string>> pixelIdData ={
   {"0000",
    "1111",
    "0000"},

   {"11",
    "11"},

   {"000",
    "111",
    "010"},

   {"110",
    "011"},

   {"011",
    "110"},

   {"111",
    "100"},

   {"111",
    "001"}
};
class Game;
class Brick{
   Game* game;
   int row, col;
   int type, color;
   vector<string> data;
   vector<Pixel> pixels;
public:
   vector<Pixel> createPixels(vector<string> data);
   Brick(Game* _game, int _row =0, int _col =0);
   vector<Pixel> getPixels() {return pixels;}
   int getRow() {return row;}
   int getCol() {return col;}
   int getColor() {return color;}
   bool canFall();
   void fall();
   void moveDown();
   void moveToBottom();
   bool canMoveLeft();
   void moveLeft();
   bool canMoveRight();
   void moveRight();
   bool isPixelsValid(vector<Pixel> pixels);
   void spin();
};
#endif // BRICK_H
