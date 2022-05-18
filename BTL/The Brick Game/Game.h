#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include "Brick.h"
using namespace std;
class Game{
   SDL_Renderer* renderer;
   bool running;
   vector<vector<char>> board;///save pixel 's color
   Brick brick;
   int score;
   SDL_Texture* bg, *tiles;
public:
   Game(SDL_Renderer* ren);
   ~Game();
   void loadMedia();
   bool isRunning() {return running ==true;}
   vector<vector<char>> getBoard() {return board;}
   void drawBackGround();
   void drawPixel(int row, int col, int color);
   void drawBrick();
   void drawBoard();
   void listen(SDL_Event event);
   void appendBrickToBoard();
   bool isRowFull(int row);
   int countFullRow();
   void removeFullRow();
   void updateScore(int fullRow);
   void update();
   void render();
};
#endif // GAME_H
