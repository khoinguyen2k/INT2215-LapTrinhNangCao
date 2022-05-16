#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Game.h"
using namespace std;

const int START_CORNER[] ={28, 31};
const int PIXEL_SIZE =18;
const int NUM_ROW =20;
const int NUM_COLUMN =10;

int main(int argc, char* agrv[])
{
   srand(time(0));
   SDL_Window* window;
   SDL_Renderer* renderer;
   initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

   Game game(renderer);
   do
   {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
         game.listen(event);
      }
      game.update();
      game.render();
      SDL_Delay(2);
   }
   while (game.isRunning());
   game.render();
   waitUntilKeyPressed();

   quitSDL(window, renderer);
   return 0;
}


