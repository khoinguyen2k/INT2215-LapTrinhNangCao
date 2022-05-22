#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Game.h"
#include "Menu.h"
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
   initSDL_ttf();
   initSDL_mixer();

   Menu startMenu({startButton});
   Menu typeMenu({typeA_button, typeB_button});
   startMenu.setTexture(loadTexture("images/start menu.png", renderer));
   typeMenu.setTexture(loadTexture("images/type menu.png", renderer));
   Menu menu =startMenu;
   bool menuIsRunning =true;

   Game game(renderer);
   menu.draw(renderer);
   SDL_Event menuEvent;
   while (menuIsRunning)
   {
      while (SDL_PollEvent(&menuEvent))
      {
         if (menuEvent.type ==SDL_QUIT) {menuIsRunning =false; break;}
         if (menuEvent.type ==SDL_MOUSEBUTTONDOWN)
         {
            menu.handleMouseEvent(menuEvent);
            if (menu.getChoice() ==startButton)
            {
               menu =typeMenu;
               menu.draw(renderer);
            }
            else if (menu.getChoice() ==typeA_button)
               game.runClassic();
            else if (menu.getChoice() ==typeB_button)
               game.runInvis();

         }
      }
      SDL_Delay(1);
      menuIsRunning =game.isRunning();
   }
   game.renderEndGame();

   waitUntilKeyPressed();
   quitSDL(window, renderer);
   return 0;
}

