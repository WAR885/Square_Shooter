#ifndef GAME_PAGE_H
#define GAME_PAGE_H
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
#include <Page.h>
#include <Text.h>
#include <Player.h>
#include <Enemy.h>
#include <Enemy_Manager.h>

class Game_Page : public Page
{
    public:
      Game_Page(SDL_Renderer *renderer);
      virtual ~Game_Page();
      void render(SDL_Renderer *renderer);
      SDL_Texture *backround_texture;
      SDL_Surface *backround_surface;
      bool player_is_dead()
      {
        return main_player.Health <= 0;
       }
         void Reset();
    protected:

    private:
const Uint8*keystate=SDL_GetKeyboardState(NULL);
  int framecount = 0;
  Player main_player;
  Text LivesText;
  Text ScoreText;
  int GameScore = 0;
  Enemy_Manager enemy_manager;
};

#endif // GAME_PAGE_H
