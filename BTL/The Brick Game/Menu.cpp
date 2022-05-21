#include "Menu.h"
#include <vector>
#include "SDL_utils.h"
using namespace std;

Menu::Menu(vector<Button> _buttons):
   buttons(_buttons),
   choiceButton(nullButton)
{}
void Menu::addButton(int a, int b, int c, int d)
{
   buttons.push_back(Button(a, b, c, d));
}
void Menu::addButton(Button button)
{
   buttons.push_back(button);
}
void Menu::handleMouseEvent(SDL_Event event)
{
   Point mousePos(event.button.x, event.button.y);
   for (size_t i =0; i <buttons.size(); i++)
   if (buttons[i].isInside(mousePos))
   {
      choiceButton =buttons[i];
      break;
   }
}

