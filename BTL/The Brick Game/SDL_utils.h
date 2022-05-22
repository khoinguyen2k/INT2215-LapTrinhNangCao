#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <string>
using namespace std;

const int SCREEN_WIDTH =320;
const int SCREEN_HEIGHT =480;
const string WINDOW_TITLE ="The Brick Game.";
const SDL_Color DEFAULT_COLOR ={255, 255, 255};
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
   const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT, const string &WINDOW_TITLE);
void logSDLError(ostream& os, const string &msg, bool fatal =false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
//SDL_image
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
//SDL_ttf
void initSDL_ttf();
SDL_Texture* loadFont(const char* path, const char* text, int fsize, SDL_Renderer* renderer);
//SDL_mixer
void initSDL_mixer();
#endif // SDL_utils.h
