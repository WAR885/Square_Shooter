#ifndef BUTTON_H
#define BUTTON_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <Text.h>
using namespace std;

class Button
{
public:
    Button()
    {
    }
    Button(int x, int y, int w, int h, int r, int g, int b, SDL_Event event, string text);
    virtual ~Button();
    void render(SDL_Renderer *renderer);
    void HandleClick()
    {
        if (MouseCheck())
        {
            SDL_PushEvent(&event);
        }
    }
    bool MouseCheck();

protected:
private:
    string text;
    SDL_Event event;
    SDL_Color color;
    SDL_Rect box;
    Text button_text;
};

#endif // BUTTON_Ht
