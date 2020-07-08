#ifndef _PAGE_MANAGER
#define _PAGE_MANAGER
#include <SDL2/SDL.h>
#include "Game_Page.h"
#include "Game_Over_Page.h"
#include "Page.h"
#include "Start_Game_Page.h"

class Page_Manager
{
public:
  Page_Manager(SDL_Window *window)
  {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    page_list[0] = new Start_Game_Page();
    page_list[1] = new Game_Page();
    page_list[2] = new Game_Over_Page();
    current_page_index = 0;
  }
  virtual ~Page_Manager()
  {
    delete page_list[0];
    delete page_list[1];
    delete page_list[2];
  }
  Page *page_list[3];
  int current_page_index;
  void page_render()
  {
    page_list[current_page_index]->render(renderer);
    if (current_page_index == 1 && ((Game_Page *)page_list[1])->player_is_dead())
    {
      current_page_index = 2;
    }
  }
  void start();
  SDL_Renderer *renderer;
};
#endif