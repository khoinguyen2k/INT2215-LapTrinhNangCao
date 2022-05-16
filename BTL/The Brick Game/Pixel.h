#ifndef PIXEL_H
#define PIXEL_H

class Game;
class Pixel{
   Game *game;
   int id_x, id_y;
public:
   Pixel(Game* _game, int x =0, int y =0);
   int getId_x() {return id_x;}
   int getId_y() {return id_y;}
   bool canFall();
   void fall();
   bool canMoveLeft();
   void moveLeft();
   bool canMoveRight();
   void moveRight();
};
#endif // DOT_H
