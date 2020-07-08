#ifndef PAGE_H
#define PAGE_H
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

class Page
{
    public:
        virtual void render(SDL_Renderer* renderer) = 0;
        Page();
        virtual ~Page();
        virtual void HandleEvent (SDL_Event event)
        {

        }
        virtual void Reset()
        {
        
        }
    protected:
    private:
};

#endif // PAGE_H
