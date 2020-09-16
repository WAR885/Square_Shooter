#include "Button.h"

Button::Button(int x, int y, int w, int h, int r, int g, int b, SDL_Event _event, string _text)
{
    //ctor
    text = _text;
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 0;
    event = _event;
    TTF_Font *pixel_font = TTF_OpenFont("C:/Users/Ashton/Desktop/Game/Code blocks games/Game 1/bin/VT323-Regular.ttf", 24);
    button_text = Text(x + 10, y, w - 20, h, pixel_font, 255, 255, 255);
}
void Button::render(SDL_Renderer *renderer)
{
    if (MouseCheck())
    {
        button_text.SetColor(150, 150, 150);
    }
    else
    {
        button_text.SetColor(255, 255, 255);
    }
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &(box));
    button_text.render(renderer, text);
}
bool Button::MouseCheck()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > box.x && y > box.y && x < box.x + box.w && y < box.y + box.h)
    {
        return true;
    }
    return false;
}

Button::~Button()
{
    //dtor
}
