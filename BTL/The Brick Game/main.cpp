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

void drawStartMenu(SDL_Renderer* renderer);
void drawTypeMenu(SDL_Renderer* renderer);
int main(int argc, char* agrv[])
{
   srand(time(0));
   SDL_Window* window;
   SDL_Renderer* renderer;
   initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

   Menu startMenu({startButton});
   Menu typeMenu({firstTypeButton, secondTypeButton});
   Menu menu({startButton});
   bool menuIsRunning =true;

   Game game(renderer);
   drawStartMenu(renderer);
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
               drawTypeMenu(renderer);
            }
            else if (menu.getChoice() ==firstTypeButton)
            {
               game.runClassic();
            }
            else if (menu.getChoice() ==secondTypeButton)
            {
               game.runInvis();
            }

         }
      }
      SDL_Delay(2);
      menuIsRunning =game.isRunning();
   }
   game.renderClassic();

   waitUntilKeyPressed();
   quitSDL(window, renderer);
   return 0;
}

void drawStartMenu(SDL_Renderer* renderer)
{
   SDL_Texture* tex =loadTexture("images/start menu.png", renderer);
   SDL_Rect src; src.x =0; src.y =0;
   SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
   SDL_RenderCopy(renderer, tex, &src, &src);
   SDL_RenderPresent(renderer);
   //SDL_DestroyTexture(tex);
}
void drawTypeMenu(SDL_Renderer* renderer)
{
   SDL_Texture* tex =loadTexture("images/type menu.png", renderer);
   SDL_Rect src; src.x =0; src.y =0;
   SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
   SDL_RenderCopy(renderer, tex, &src, &src);
   SDL_RenderPresent(renderer);
   //SDL_DestroyTexture(tex);
}
