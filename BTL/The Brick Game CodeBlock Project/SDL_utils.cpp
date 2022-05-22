#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "SDL_utils.h"
using namespace std;

void logSDLError(ostream& os, const string &msg, bool fatal)
{
   os <<msg <<" Error: " <<SDL_GetError() <<endl;
   if (fatal) {
      SDL_Quit();
      exit(1);
   }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
   const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT, const string &WINDOW_TITLE)
{
   if (SDL_Init(SDL_INIT_EVERYTHING !=0))
      logSDLError(std::cout, "SDL_Init", true);
   window =SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
   //test at home
   if (window ==nullptr) logSDLError(std::cout, "CreateWindow", true);
   renderer =SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
void waitUntilKeyPressed()
{
   SDL_Event e;
   while (true)
   {
      if (SDL_WaitEvent(&e) !=0 &&
          (e.type ==SDL_KEYDOWN || e.type ==SDL_QUIT) )
         return;
      SDL_Delay(100);
   }
}

// SDL_image
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer)
{
   SDL_Texture* newTexture =nullptr;
   SDL_Surface* loadedSurface =IMG_Load(path.c_str() );
   if (loadedSurface ==nullptr)
      cout <<"Unable to load image " <<path <<" SDL_image Error: "
      <<IMG_GetError() <<endl;
   else
   {
      newTexture =SDL_CreateTextureFromSurface(renderer, loadedSurface);
      if (newTexture ==nullptr)
         cout <<"Unable to create texture from " <<path <<" SDL Error: "
         <<SDL_GetError() <<endl;
      SDL_FreeSurface(loadedSurface);
   }
   return newTexture;
}

// SDL_ttf
void initSDL_ttf()
{
   if (TTF_Init() <0)
   {
      cout <<"TTF_Init Error: " <<TTF_GetError() <<endl;
      exit(1);
   }
}
SDL_Texture* loadFont(const char* path, const char* text, int fsize, SDL_Renderer* renderer)
{
   TTF_Font* font =TTF_OpenFont(path, fsize);
   SDL_Surface* surface =TTF_RenderText_Blended(font, text, DEFAULT_COLOR);
   SDL_Texture* texture =SDL_CreateTextureFromSurface(renderer, surface);
   return texture;
}

// SDL_mixer
void initSDL_mixer()
{
   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) <0)
   {
      cout <<"Mixer_Init Error: " <<Mix_GetError() <<endl;
      exit(1);
   }
}
