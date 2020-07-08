#ifndef GAME_OVER_PAGE_H
#define GAME_OVER_PAGE_H
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

class Game_Over_Page : public Page
{
    public:
        Game_Over_Page();
        virtual ~Game_Over_Page();
        void render(SDL_Renderer* renderer);
    Button RetryButton;
    void HandleEvent (SDL_Event event)
        {
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
RetryButton.HandleClick();
    }
        }
    protected:

    private:
    Text OverText;
};

#endif // GAME_OVER_PAGE_H
