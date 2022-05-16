#include "Game.h"
#include "SDL_utils.h"
#include "Timer.h"
#include <cmath>

void Game::loadMedia()
{
   bg =loadTexture("images/background.png", renderer);
   tiles =loadTexture("images/tiles.png", renderer);
}
Game::Game(SDL_Renderer* ren):
   renderer(ren),
   running(true),
   board(10, vector<char> (20, '0')),
   brick(this, 3, 0)
{
   loadMedia();
}

void Game::listen(SDL_Event event)
{
   if (event.type ==SDL_QUIT) running =false;
   if (event.type ==SDL_KEYDOWN)
      switch (event.key.keysym.sym)
      {
         case SDLK_q: running =false; break;
         case SDLK_LEFT: brick.moveLeft(); break;
         case SDLK_RIGHT: brick.moveRight(); break;
         case SDLK_SPACE: brick.moveToBottom(); break;
         case SDLK_UP: brick.spin(); break;
         case SDLK_DOWN: brick.moveDown(); break;
         default: break;
      }
}
void Game::drawBackGround()
{
   SDL_Rect src; src.x =0; src.y =0;
   SDL_QueryTexture(bg, NULL, NULL, &src.w, &src.h);
   SDL_RenderCopy(renderer, bg, &src, &src);
}
void Game::drawPixel(int id_x, int id_y)
{
   SDL_Rect src ={0, 0, 18, 18};
   SDL_Rect dst ={28 +18 *id_x, 31 +18 *id_y, 18, 18};///corner ={28, 31};
   SDL_RenderCopy(renderer, tiles, &src, &dst);
}
void Game::drawBrick()
{
   vector<Pixel> pixels =brick.getPixels();
   for (int i =0; i <4; i++)
      drawPixel(pixels[i].getId_x(), pixels[i].getId_y());
}
void Game::drawBoard()
{
   for (int i =0; i <10; i++)
   for (int j =0; j <20; j++)
      if (board[i][j] !='0') drawPixel(i, j);
}
void Game::appendBrickToBoard()
{
   vector<Pixel> pixels =brick.getPixels();
   for (int i =0; i <4; i++)
      board[pixels[i].getId_x()][pixels[i].getId_y()] ='1';
}
bool Game::isRowFull(int row)
{
   bool res =true;
   return res;
}
void Game::clearAllFullRow()
{

}
void Game::update()
{
   static Timer timer;
   if (timer.isFullCharged())
   {
      if (brick.canFall())
         brick.fall();
      else
      {
         appendBrickToBoard();
         Brick newBrick(this, 4, 0);
         if (!newBrick.canFall())
            running =false;
         else brick =newBrick;
      }
   }
}
void Game::render()
{
   drawBackGround();
   drawBrick();
   drawBoard();
   SDL_RenderPresent(renderer);
}
