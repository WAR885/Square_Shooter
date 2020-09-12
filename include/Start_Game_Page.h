#ifndef START_GAME_PAGE_H
#define START_GAME_PAGE_H
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
#include <Button.h>

class Start_Game_Page : public Page
{
public:
    Start_Game_Page(SDL_Renderer *renderer);
    virtual ~Start_Game_Page();
    void render(SDL_Renderer *renderer);
    Button StartButton;
    Button ExitButton;
    void HandleEvent(SDL_Event event)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            StartButton.HandleClick();
            ExitButton.HandleClick();
        }
    }

protected:
private:
    Text OverText;
};

#endif // START_GAME_PAGE_H
