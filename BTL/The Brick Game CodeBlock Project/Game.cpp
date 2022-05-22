#include "Game.h"
#include "SDL_utils.h"
#include "Timer.h"
#include <cmath>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using namespace std;

const char* intTo6Digit(int n)
{
   if (n >=99999)
      return "999999";
   string ans ="000000";
   for (int i =5; i >=0; i--)
   {
      ans[i] +=n %10;
      n /=10;
   }
   return ans.c_str();
}
const string quitGuide ="Press any key to exit";
void Game::loadMedia()
{
   background =loadTexture("images/background.png", renderer);
   tiles =loadTexture("images/tiles.png", renderer);
   frame =loadTexture("images/frame.png", renderer);
   endTexture =loadTexture("images/game over.png", renderer);
   quitTexture =loadFont("Vn Truyen Tranh Biqit.ttf", quitGuide.c_str(), 72, renderer);
   scoreTexture =loadFont("Vn Truyen Tranh Biqit.ttf", intTo6Digit(score), 72, renderer);
   dropSound =Mix_LoadWAV("sounds/drop-sound.wav");
   boomSound =Mix_LoadWAV("sounds/boom-sound.wav");
}
Game::Game(SDL_Renderer* ren):
   renderer(ren),
   running(true),
   board(20, vector<char> (10, '0')),
   brick(this, 0, 3),
   score(0)
{
   loadMedia();
}
Game::~Game()
{
   SDL_DestroyTexture(background);
   SDL_DestroyTexture(tiles);
   SDL_DestroyTexture(frame);
   SDL_DestroyTexture(endTexture);
   SDL_DestroyTexture(scoreTexture);
   SDL_DestroyTexture(quitTexture);
   Mix_FreeChunk(dropSound);
   Mix_FreeChunk(boomSound);
   TTF_Quit();
   Mix_Quit();
}

void Game::listen(SDL_Event event)
{
   if (event.type ==SDL_QUIT) running =false;
   if (event.type ==SDL_KEYDOWN)
      switch (event.key.keysym.sym)
      {
         //case SDLK_q: running =false; break;
         case SDLK_UP: brick.spin(); break;
         case SDLK_LEFT: brick.moveLeft(); break;
         case SDLK_RIGHT: brick.moveRight(); break;
         case SDLK_SPACE: brick.moveToBottom(); break;
         case SDLK_DOWN: brick.moveDown(); break;
         default: break;
      }
}
void Game::draw(SDL_Texture* tex, int x, int y)
{
   SDL_Rect src; src.x =0; src.y =0;
   SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
   SDL_Rect dst ={x, y, src.w, src.h};
   SDL_RenderCopy(renderer, tex, &src, &dst);
}
void Game::drawPixel(int row, int col, int color)
{
   SDL_Rect src ={18 *color, 0, 18, 18};
   ///col in Ox, row in Oy
   SDL_Rect dst ={28 +18 *col, 31 +18 *row, 18, 18};///corner ={28, 31};
   SDL_RenderCopy(renderer, tiles, &src, &dst);
}
void Game::drawBrick()
{
   vector<Pixel> pixels =brick.getPixels();
   for (int i =0; i <4; i++)
      drawPixel(pixels[i].getRow(), pixels[i].getCol(), pixels[i].getColor());
}
void Game::drawBoard()
{
   for (int row =0; row <20; row++)
   for (int col =0; col <10; col++)
      if (board[row][col] !='0') drawPixel(row, col, (int)(board[row][col] -'1'));
}
void Game::appendBrickToBoard()
{
   vector<Pixel> pixels =brick.getPixels();
   for (int i =0; i <4; i++)
      board[pixels[i].getRow()][pixels[i].getCol()] =(char)('1' +pixels[i].getColor());
}
bool Game::isRowFull(int row)
{
   bool ans =true;
   for (size_t col =0; col <10; col++)
      if (board[row][col] =='0') ans =false;
   return ans;
}
int Game::countFullRow()
{
   int res =0;
   for (size_t pos =0; pos <20; pos++)
      if (isRowFull(pos)) res++;
   return res;
}
void Game::removeFullRow()
{
   for (size_t pos =0; pos <20; pos++)
   if (isRowFull(pos))
   {
      for (size_t row =pos; row >=1; row--)
         board[row] =board[row -1];
      for (size_t col =0; col <10; col++)
         board[0][col] ='0';
   }
}
void Game::updateScore(int fullRow)
{
   switch (fullRow)
   {
      case 1: score +=100; break;
      case 2: score +=200; break;
      case 3: score +=400; break;
      case 4: score +=1200; break;
      default: break;
   }
}
void Game::playSound(int fullRow)
{
   switch (fullRow)
   {
      case 1: case 2: case 3:
         Mix_PlayChannel(-1, dropSound, 0);
         SDL_Delay(100);
      break;
      case 4:
         Mix_PlayChannel(-1, boomSound, 0);
         SDL_Delay(400);
      break;
      default: break;
   }
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
         updateScore(countFullRow());
         playSound(countFullRow());
         removeFullRow();
         Brick newBrick(this, 0, 3);
         brick =newBrick;
         if (!newBrick.canFall())
            running =false;
      }
   }
}
void Game::drawScore()
{
   scoreTexture =loadFont("Vn Truyen Tranh Biqit.ttf", intTo6Digit(score), 72, renderer);
   SDL_Rect dst ={250, 52, 62, 30};
   SDL_RenderCopy(renderer, scoreTexture, NULL, &dst);
}
void Game::drawEndScreen()
{
   draw(endTexture, 78, 186);
   //final score
   scoreTexture =loadFont("Vn Truyen Tranh Biqit.ttf", intTo6Digit(score), 72, renderer);
   SDL_Rect dst ={130, 247, 62, 30};
   SDL_RenderCopy(renderer, scoreTexture, NULL, &dst);
   //quit guide
   SDL_Rect _dst ={16, 415, 284, 40};
   SDL_RenderCopy(renderer, quitTexture, NULL, &_dst);

}

void Game::renderClassic()
{
   draw(background);
   drawBrick();
   drawBoard();
   draw(frame);
   drawScore();
   SDL_RenderPresent(renderer);
}
void Game::renderInvis()
{
   draw(background);
   drawBrick();
   draw(frame);
   drawScore();
   SDL_RenderPresent(renderer);
}

void Game::runClassic()
{
   do
   {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
         listen(event);
      }
      update();
      renderClassic();
      SDL_Delay(1);
   }
   while (isRunning());
}
void Game::runInvis()
{
   do
   {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
         listen(event);
      }
      update();
      renderInvis();
      SDL_Delay(1);
   }
   while (isRunning());
}
void Game::renderEndGame()
{
   draw(background);
   drawBrick();
   drawBoard();
   draw(frame);

   drawEndScreen();
   SDL_RenderPresent(renderer);
}
