//Using SDL and standard IO
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
#include "Enemy.h"
#include "big_Enemy.h"
#include "spin_Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Common.h"
#include "Enemy_Manager.h"
#include "Text.h"
#include "Page_Manager.h"
using namespace std;

int main( int argc, char* args[] )
{
    cout << "main"<< endl;
    srand(time(NULL));
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            IMG_Init(IMG_INIT_PNG);
            TTF_Init();
            //Get window surface
            bool ifAnimation = false;
            Page_Manager page_manager(window);
            // if (pixel_font == NULL)
            // {
            //     cout<<"could not load text"<<endl;
            //     printf("Error: %s\n",TTF_GetError());
            // }
           page_manager.start ();
        }

        //Destroy window
        SDL_DestroyWindow( window );

        //Quit SDL subsystems
        SDL_Quit();

        return 0;
    }
}
