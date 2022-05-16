#ifndef BRICK_H
#define BRICK_H
#include <string>
#include <vector>
#include "Pixel.h"
using namespace std;
const vector<vector<string>> pixelIdData ={
   {"1111",
    "0000"},

   {"11",
    "11"},

   {"111",
    "010"},

   {"110",
    "011"},

   {"011",
    "110"},

   {"10",
    "10",
    "11"},

   {"01",
    "01",
    "11"}
};
class Game;
class Brick{
   Game* game;
   int id_x, id_y;
   int type;
   vector<string> data;
   vector<Pixel> pixels;
public:
   vector<Pixel> createPixels(vector<string> data);
   Brick(Game* _game, int x =0, int y =0);
   vector<Pixel> getPixels() {return pixels;}
   int getId_x() {return id_x;}
   int getId_y() {return id_y;}
   bool canFall();
   void fall();
   void moveDown();
   void moveToBottom();
   bool canMoveLeft();
   void moveLeft();
   bool canMoveRight();
   void moveRight();
   void spin();
};
#endif // BRICK_H
