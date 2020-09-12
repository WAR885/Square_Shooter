#include "Start_Game_Page.h"
#include "Events.h"

Start_Game_Page::Start_Game_Page(SDL_Renderer *renderer) : Page()
{
  //ctor
  TTF_Font *pixel_font = TTF_OpenFont("C:/Users/Ashton/Desktop/Game/Code blocks games/Game 1/bin/VT323-Regular.ttf", 24);
  OverText = Text(70, 50, 500, 100, pixel_font);
  SDL_Event event;
  SDL_zero(event);
  event.type = ResetGame;
  SDL_Event quit_event;
  SDL_zero(quit_event);
  quit_event.type = SDL_QUIT;
  cout << event.type << endl;
  StartButton = Button(170, 200, 300, 100, 255, 255, 255, event, "Start");
  ExitButton = Button(170, 300, 300, 100, 255, 255, 255, quit_event, "Exit");
}

Start_Game_Page::~Start_Game_Page()
{
  //dtor
}

void Start_Game_Page::render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  OverText.render(renderer, "Square Shooter");
  StartButton.render(renderer);
  ExitButton.render(renderer);
  SDL_RenderPresent(renderer);
}
