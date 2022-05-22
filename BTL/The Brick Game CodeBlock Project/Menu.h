#ifndef MENU_H
#define MENU_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
struct Point{
   int x, y;
   Point(int _x =0, int _y =0): x(_x), y(_y)
   {}
};
struct Button{
   vector<Point> points;
   Button(int a =0, int b =0, int c =0, int d =0):
   points(2)
   {
      points[0] =Point(a, b);
      points[1] =Point(c, d);
   }
   bool isInside(Point p)
   {
      return (points[0].x <=p.x && p.x <=points[1].x && points[0].y <=p.y && p.y <=points[1].y);
   }
   bool operator==(Button b)
   {
      return ((points[0].x ==b.points[0].x) && (points[0].y ==b.points[0].y)
              && (points[1].x ==b.points[1].x) && (points[1].y ==b.points[1].y));
   }
};

const Button startButton(78, 244, 241, 293);
const Button typeA_button(35, 177, 232, 215);
const Button typeB_button(35, 276, 241, 317);
const Button nullButton;
class Menu{
   vector<Button> buttons;
   Button choiceButton;
   SDL_Texture* texture;
public:
   Menu(vector<Button> _buttons);
   ~Menu();
   void setTexture(SDL_Texture* tex){texture =tex;}
   void draw(SDL_Renderer* renderer);
   Button getChoice(){return choiceButton;}
   void addButton(int a, int b, int c, int d);
   void addButton(Button button);
   void handleMouseEvent(SDL_Event event);

};

#endif // MENU_H
