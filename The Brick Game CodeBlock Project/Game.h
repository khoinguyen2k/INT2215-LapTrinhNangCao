#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "Brick.h"
using namespace std;
class Game{
   SDL_Renderer* renderer;
   bool running;
   vector<vector<char>> board;///save pixel 's color
   Brick brick;
   int score;
   SDL_Texture* background, *tiles, *frame;
   SDL_Texture* endTexture, *quitTexture;
   SDL_Texture* scoreTexture;
   Mix_Chunk* dropSound, *boomSound;
public:
   Game(SDL_Renderer* ren);
   ~Game();
   void loadMedia();
   bool isRunning() {return running ==true;}
   vector<vector<char>> getBoard() {return board;}
   void draw(SDL_Texture* tex, int x =0, int y =0);
   void drawPixel(int row, int col, int color);
   void drawBrick();
   void drawBoard();
   void drawScore();
   void playSound(int fullRow);
   void drawEndScreen();
   void listen(SDL_Event event);
   void appendBrickToBoard();
   bool isRowFull(int row);
   int countFullRow();
   void removeFullRow();
   void updateScore(int fullRow);
   void update();
   void renderClassic();
   void renderInvis();

   void runClassic();
   void runInvis();
   void renderEndGame();
};
#endif // GAME_H
