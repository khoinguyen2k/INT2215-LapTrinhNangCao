#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include "Brick.h"
using namespace std;
class Game{
   SDL_Renderer* renderer;
   bool running;
   vector<vector<char>> board;
   Brick brick;

   SDL_Texture* bg, *tiles;
public:
   Game(SDL_Renderer* ren);
   void loadMedia();
   bool isRunning() {return running ==true;}
   vector<vector<char>> getBoard() {return board;}
   void drawBackGround();
   void drawPixel(int id_x, int id_y);
   void drawBrick();
   void drawBoard();
   void listen(SDL_Event event);
   void appendBrickToBoard();
   bool isRowFull(int row);
   void clearAllFullRow();
   void update();
   void render();
};
#endif // GAME_H
