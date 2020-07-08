#ifndef TEXT_H
#define TEXT_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL_image.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

class Text
{
public:
    Text()
    {
    }
    Text(int x, int y, int width, int height, TTF_Font *_font, int r = 0, int g = 0, int b = 0);
    virtual ~Text();
    TTF_Font *font;
    SDL_Color text_color;
    SDL_Rect text_pos;
    void render(SDL_Renderer *renderer, string inGameText);
    void SetColor(int r, int g, int b);

protected:
private:
};

#endif // TEXT_H
