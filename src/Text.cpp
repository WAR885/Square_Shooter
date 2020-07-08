#include "Text.h"

Text::Text(int x, int y, int width, int height, TTF_Font *_font, int r, int g, int b)
{
  text_color = {r, g, b};
  text_pos.x = x;
  text_pos.y = y;
  text_pos.w = width;
  text_pos.h = height;
  font = _font;
}
void Text::render(SDL_Renderer *renderer, string inGameText)
{
  SDL_Surface *TextSurface = TTF_RenderText_Solid(font, inGameText.c_str(), text_color);
  SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, TextSurface);
  SDL_RenderCopy(renderer, text_texture, NULL, &text_pos);
}
void Text::SetColor(int r, int g, int b)
{
  text_color = {r, g, b};
}

Text::~Text()
{
}
