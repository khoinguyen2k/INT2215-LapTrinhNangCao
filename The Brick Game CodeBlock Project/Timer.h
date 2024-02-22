#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <SDL.h>
const int STEP_DELAY =200;
class Timer{
   clock_t startTime;
   clock_t endTime;
public:
   Timer(){ startTime =SDL_GetTicks(); SDL_Delay(1); }
   int getElapsed(){
      endTime =SDL_GetTicks();
      return (endTime -startTime);
   }
   bool isFullCharged(){
      if (getElapsed() >=STEP_DELAY){
         startTime =endTime; //reset timer for next count
         return true;
      }
      else return false;
   }
};

#endif
