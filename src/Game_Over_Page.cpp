#include "Game_Over_Page.h"
#include "Events.h"

Game_Over_Page::Game_Over_Page() : Page()
{
  //ctor
  TTF_Font *pixel_font = TTF_OpenFont("C:/Users/Ashton/Desktop/Game/Code blocks games/Game 1/bin/VT323-Regular.ttf", 24);
  OverText = Text(70, 280, 500, 100, pixel_font);
  SDL_Event event;
  SDL_zero(event);
  event.type = ResetGame;
  cout << event.type << endl;
  RetryButton = Button(170, 400, 300, 100, 255, 255, 255, event, "Restart");
}

Game_Over_Page::~Game_Over_Page()
{
  //dtor
}

void Game_Over_Page::render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  OverText.render(renderer, "Game Over");
  RetryButton.render(renderer);
  SDL_RenderPresent(renderer);
}
