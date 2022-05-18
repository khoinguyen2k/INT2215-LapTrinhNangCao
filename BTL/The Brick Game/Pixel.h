#ifndef PIXEL_H
#define PIXEL_H

class Game;
class Pixel{
   Game *game;
   int row, col;
   int color;
public:
   Pixel(Game* _game, int _row =0, int _col =0);
   int getRow() {return row;}
   int getCol() {return col;}
   int getColor() {return color;}
   void setColor(int _c) {color =_c;}
   bool isInsideBoard();
   bool canFall();
   void fall();
   bool canMoveLeft();
   void moveLeft();
   bool canMoveRight();
   void moveRight();
};
#endif // DOT_H
